#include <windows.h>
#include <fstream>
#include <clocale>
#include <iostream>
#include "2.1.h"

int main(int argc, char* argv[])
{
	string Aname, Bname;
    int An, Am, Bn, Bm;
    float A[Rmax][Rmax], B[Rmax][Rmax];
    float result[Rmax];
    FILE *out;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (argc < 3)
    {
        printf("Недостаточно параметров!\n");
        return 0;
    }
    while ((An < 0) | (An > Rmax))
    {
        printf("Введите максимальное количество строк в первой матрице: ");
        scanf("%d", &An);
        if ((An < 0) | (An > Rmax))
            printf("Количество строк матрицы должно быть от 1 до %d.\n", Rmax);
    }
    while ((Am < 0) | (Am > Rmax))
    {
    	printf("Введите максимальное количество стоблцов в первой матрице: ");
        scanf("%d", &Am);
        if ((Am < 0) | (Am > Rmax))
            printf("Количество столбцов матрицы должно быть от 1 до %d.\n", Rmax);
    }
    while ((Bn < 0) | (Bn > Rmax))
    {
        printf("Введите максимальное количество строк в первой матрице: ");
        scanf("%d", &Bn);
        if ((Bn < 0) | (Bn > Rmax))
            printf("Количество строк матрицы должно быть от 1 до %d.\n", Rmax);
    }
    while ((Bm < 0) | (Bm > Rmax))
    {
    	printf("Введите максимальное количество стоблцов в первой матрице: ");
        scanf("%d", &Bm);
        if ((Bm < 0) | (Bm > Rmax))
            printf("Количество столбцов матрицы должно быть от 1 до %d.\n", Rmax);
    }
    reader (A, An, Am, argv[1]);
    reader (B, Bn, Bm, argv[2]);
    //------------------------------------
    out = fopen(argv[3], "w");
    fprintf(out,"Первая матрица: \n");
    matr_printer (A, An, Am, out);
    fprintf(out,"Вторая матрица: \n");
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
            fprintf(out,"Нет матриц с нулевыми элементами.");
    }
    fclose(out);
    return 0;
}
