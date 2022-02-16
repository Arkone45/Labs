#include <windows.h>
#include <fstream>
#include <clocale>
#include <iostream>
#include "2.1.h"

int main(int argc, char* argv[])
{
	string Aname, Bname;
    int An = 0, Am = 0, Bn = 0, Bm = 0, x[Rmax];
    float A[Rmax][Rmax], B[Rmax][Rmax];
    float result[Rmax];
    FILE *out;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (argc < 3)
    {
        printf("������������ ����������!\n");
        return 0;
    }
    while ((An <= 0) | (An > Rmax))
    {
        printf ("������� ������������ ���������� ����� � ������ �������: ");
        scanf ("%d", &An);
        if ((An < 0) | (An > Rmax))
            printf("���������� ����� ������� ������ ���� �� 1 �� %d.\n", Rmax);
    }
    while ((Am <= 0) | (Am > Rmax))
    {
    	printf ("������� ������������ ���������� �������� � ������ �������: ");
        scanf ("%d", &Am);
        if ((Am < 0) | (Am > Rmax))
            printf("���������� �������� ������� ������ ���� �� 1 �� %d.\n", Rmax);
    }
    while ((Bn <= 0) | (Bn > Rmax))
    {
        printf ("������� ������������ ���������� ����� � ������ �������: ");
        scanf ("%d", &Bn);
        if ((Bn < 0) | (Bn > Rmax))
            printf("���������� ����� ������� ������ ���� �� 1 �� %d.\n", Rmax);
    }
    while ((Bm <= 0) | (Bm > Rmax))
    {
    	printf ("������� ������������ ���������� �������� � ������ �������: ");
        scanf ("%d", &Bm);
        if ((Bm < 0) | (Bm > Rmax))
            printf("���������� �������� ������� ������ ���� �� 1 �� %d.\n", Rmax);
    }
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
    return 0;
}
