#include <stdio.h>
#include <malloc.h>
#include "8.h"


Matrix::Matrix (int a, int b) : rows(a), cols(b)
{
    if (a & !b)
    {
        rows = cols = 1;
        matr = new int* [rows];
        matr[0] = new int [cols];
        matr[0][0] = a;
    }
    else
    {
        matr = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            matr[i] = new int [cols];
            for (int j = 0; j < cols; j++)
                matr[i][j] = 0;
        }
    }
}

Matrix::~Matrix ()
{
    for (int i = 0; i < rows; i++)
        delete[] matr[i];
    rows = cols = 0;
    delete[] matr;
    printf ("Уничтожение завершено.\n");
}

Matrix::Matrix (Matrix &smpl, int incr) : Matrix (smpl.rows, smpl.cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matr[i][j] = smpl.matr[i][j] + incr;
    printf ("Копирование завершено.\n");
}

Matrix::operator double()
{
    double res;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res += matr[i][j];
    return res / (rows * cols);
}

void Matrix::change (int val, int row, int col)
{
    matr[row][col] = val;
}

void Matrix::printer ()
{
    if (rows & cols)
    {
        printf ("Строк: %d Столбцов: %d\n", rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                printf ("%d ", matr[i][j]);
            printf ("\n");
        }
    }
    else
        printf ("Матрица пуста.\n");
}
