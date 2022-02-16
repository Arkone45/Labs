#include <windows.h>
#include <fstream>
#include <clocale>
#include <iostream>
#include "3.h"

void text_to_bin (char *T_name, char *B_name, int *a, int *b, int *n)
{
    int i;
    float x[Nmax];
    FILE *text, *binar;
    if ((text = fopen (T_name, "r")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", T_name);
        exit (EXIT_FAILURE);
    }
    if ((binar = fopen (B_name, "wb")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", B_name);
        exit (EXIT_FAILURE);
    }
    fscanf(text, "%d%d", a, b);
    for (i = 0; !feof(text); i++)
        fscanf(text, "%f ", &x[i]);
    fclose (text);
    *n = i;
    fwrite (&x, i * sizeof(float), 1, binar);
    fclose (binar);
}

void printer (char *fname)
{
    int i = 0;
    float x[Nmax];
    FILE *file;
    if ((file = fopen(fname, "rb")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", fname);
        exit (EXIT_FAILURE);
    }
    for (float *ptr = x; !feof(file); ptr++)
    {
        fread(ptr, sizeof(float), 1, file);
        i++;
    }
    fclose(file);
    for (int j = 0; j < i-1; j++)
        printf(" %g |", x[j]);
    printf ("\n");
}

void replace_in_bin (char *B_name, int a, int b)
{
    FILE *binar;
    float  x[Nmax], y[Nmax];
    if ((binar = fopen (B_name, "rb+")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", B_name);
        exit (EXIT_FAILURE);
    }
    fseek (binar, (a - 1) * rec * sizeof(float), SEEK_SET);
    fread (y, sizeof(float), rec, binar);
    fseek (binar, (b - 1) * rec * sizeof(float), SEEK_SET);
    fread (x, sizeof(float), rec, binar);
    fseek (binar, (b - 1) * rec * sizeof(float), SEEK_SET);
    fwrite (y, sizeof(float), rec, binar);
    fseek (binar, (a - 1) * rec * sizeof(float), SEEK_SET);
    fwrite (x, sizeof(float), rec, binar);
    fclose (binar);
}
