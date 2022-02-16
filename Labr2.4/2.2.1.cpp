#include <windows.h>
#include <fstream>
#include <iostream>
#include "2.2.h"

using namespace std;


void reader (float **(&R), int Rn, int Rm, char *R_name)
{
    FILE *fin;
    if ((fin = fopen(R_name, "r")) == NULL)
    {
        printf("���������� ������� ���� '%s'.\n", R_name);
        exit(EXIT_FAILURE);
    }
    R = new float*[Rn];
	for (int i = 0; i < Rn; i++)
    {
        R[i] = new float[Rm];
        for (int j = 0; j < Rm; j++)
        {
            if (fscanf(fin, "%g", &R[i][j]) < 1)
            {
                printf("���������� ��������� ������� �� ����� '%s' �� ��������� � �������.\n", R_name);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(fin);
}

void matr_printer (float **R, int Rn, int Rm, FILE *fout)
{
    for (int i = 0; i < Rn; i++)
    {
        for (int j = 0; j < Rm; j++)
            fprintf(fout, "%g ", R[i][j]);
        fprintf(fout,"\n");
    }
    fprintf(fout,"\n");
}

boolean zero (float *R, int Rm)
{
    boolean result = false;
    for (int i = 0; i < Rm; i++)
        if (R[i] == 0)
            result = true;
    return result;
}
void multiplication (float **R, int Rn, int Rm, float *(&result))
{
    boolean has_zero = false;
    result = new float [Rn];
    for (int i = 0; i < Rn; i++)
    {
        result[i] = 0;
        if (zero (R[i], Rm))
            has_zero = true;
    }
    if (has_zero)
    {
        for (int i = 0; i < Rn; i++)
        {
            result[i] = 1;
            for (int j = 0; j <Rm; j++)
                if (R[i][j] != 0)
                    result[i] *= R[i][j];
        }
    }
}

void mas_printer (float *R, int Rn, FILE *fout)
{
    if (R[0] != 0)
    {
        fprintf(fout,"������������ ��������� ��������� � ������ ������: \n");
        for (int i = 0; i < Rn; i++)
            fprintf(fout, "%g\n", R[i]);
    }
}
