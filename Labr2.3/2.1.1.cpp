#include <windows.h>
#include <fstream>
#include <iostream>
#include "2.1.h"

using namespace std;


void reader (float R[][Rmax], int Rn, int Rm, char *R_name)
{
    FILE *fin;
    if ((fin = fopen(R_name, "r")) == NULL)
    {
        printf("Невозможно открыть файл '%s'.\n", R_name);
        exit(EXIT_FAILURE);
    }
	for (int i = 0; i < Rn; i++)
    {
        for (int j = 0; j < Rm; j++)
        {
            if (fscanf(fin, "%g", &R[i][j]) < 1)
            {
                printf("Количество элементов матрицы из файла '%s' не совпадает с ввдённым.\n", R_name);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(fin);
}

void matr_printer (float R[][Rmax], int Rn, int Rm, FILE *fout)
{
    for (int i = 0; i < Rn; i++)
    {
        for (int j = 0; j < Rm; j++)
          fprintf(fout, "%g ", R[i][j]);
        fprintf(fout,"\n");
    }
    fprintf(fout,"\n");
}

int row_has_zero (float R[], int Rm)
{
    int result = 0;
    int i = 0;
    while ((i < Rm) & (!result))
    {
        if (R[i] == 0)
            result = 1;
        i++;
    }
    return result;
}

int matr_has_zero (float R[][Rmax], int Rn, int Rm)
{
    int result = 0;
    int i = 0;
    while ((i < Rn) & (!result))
    {
        if (row_has_zero (R[i], Rm))
            result = 1;
        i++;
    }
    return result;
}

void multiplication (float R[][Rmax], int Rn, int Rm, float result[])
{
    if (matr_has_zero (R, Rn, Rm))
    {
        result[0] = 0;
        for (int i = 0; i < Rn; i++)
        {
            result[i] = 1;
            for (int j = 0; j <Rm; j++)
                if (R[i][j] != 0)
                    result[i] *= R[i][j];
        }
    }
}

void mas_printer (float R[], int Rn, FILE *fout)
{
    if (R[0] != 0)
    {
        fprintf(fout,"Произведение ненулевых элементов в каждой строке: \n");
        for (int i = 0; i < Rn; i++)
            fprintf(fout, "%g\n", R[i]);
    }
}
