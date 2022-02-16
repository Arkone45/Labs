#include <windows.h>
#include <fstream>
#include <clocale>
#include <iostream>
#include "2.2.h"

int main(int argc, char* argv[])
{
	string Aname, Bname;
    int An, Am, Bn, Bm;
    float **A, **B;
    float *result;
    int *zeros;
    FILE *out;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (argc < 3)
    {
        printf("Недостаточно параметров!\n");
        return 0;
    }
    printf("Введите максимальное количество строк в первой матрице: ");
    scanf ("%d", &An);
    printf("Введите максимальное количество стоблцов в первой матрице: ");
    scanf ("%d", &Am);
    printf("Введите максимальное количество строк в первой матрице: ");
    scanf ("%d", &Bn);
    printf("Введите максимальное количество стоблцов в первой матрице: ");
    scanf ("%d", &Bm);
    reader (A, An, Am, argv[1]);
    reader (B, Bn, Bm, argv[2]);
    //------------------------------------
    out = fopen(argv[3], "w");
    fprintf(out,"Первая матрица: \n");
    matr_printer (A, An, Am, out);
    fprintf(out,"Вторая матрица: \n");
    matr_printer (B, Bn, Bm, out);
    //------------------------------------
    zero(A, An, Am, zeros);
    multiplication (A, An, Am, zeros, result);
    if (result[0] != 0)
        mas_printer (result, An, out);
    else
    {
        zero(B, Bn, Bm, zeros);
        multiplication (B, Bn, Bm, zeros, result);
        if (result[0] != 0)
            mas_printer (result, Bn, out);
        else
            fprintf(out,"Нет матриц с нулевыми элементами.");
    }
    fclose(out);
    for (int i = 0; i < An; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    for (int i = 0; i < Bn; i++)
    {
        delete[] B[i];
    }
    delete[] B;
    delete[] result;
    delete[] zeros;
    return 0;
}
