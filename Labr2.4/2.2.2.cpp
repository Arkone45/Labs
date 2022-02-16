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
    FILE *out;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (argc < 3)
    {
        printf("������������ ����������!\n");
        return 0;
    }
    printf("������� ������������ ���������� ����� � ������ �������: ");
    scanf("%d", &An);
    printf("������� ������������ ���������� �������� � ������ �������: ");
    scanf("%d", &Am);
    printf("������� ������������ ���������� ����� � ������ �������: ");
    scanf("%d", &Bn);
    printf("������� ������������ ���������� �������� � ������ �������: ");
    scanf("%d", &Bm);
    reader (A, An, Am, argv[1]);
    reader (B, Bn, Bm, argv[2]);
    //------------------------------------
    out = fopen(argv[3], "w");
    fprintf(out,"������ �������: \n");
    matr_printer (A, An, Am, out);
    fprintf(out,"������ �������: \n");
    matr_printer (B, Bn, Bm, out);
    //------------------------------------
    multiplication (A, An, Am, result);
    if (result[0] != 0)
        mas_printer (result, An, out);
    else
    {
        multiplication (B, Bn, Bm, result);
        if (result[0] != 0)
            mas_printer (result, Bn, out);
        else
            fprintf(out,"��� ������ � �������� ����������.");
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
}
