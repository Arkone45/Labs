#include <stdio.h>
#include <malloc.h>
#include <exception>
#include <stdexcept>
#include "10.h"


Matrix::Matr_row::Matr_row (int *r, int l) : row(r)
{
    //if ((n < 0) | (n >= l))
    len = l;
}

Matrix::Matr_row::~Matr_row ()
{
    //delete[] row;
    printf ("����������� ���� ���������.\n");
}

int Matrix::Matr_row::operator [] (int indx)
{
    return row[indx];
}

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
    printf ("����������� ���������.\n");
}

Matrix::Matrix (Matrix &smpl, int incr) : Matrix (smpl.rows, smpl.cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matr[i][j] = smpl.matr[i][j] + incr;
    printf ("����������� ���������.\n");
}

Matrix::operator double()
{
    double res;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res += matr[i][j];
    return res / (rows * cols);
}

Matrix&  Matrix::operator = (const Matrix &smpl)
{
    if (this == &smpl)
        return *this;
    this->~Matrix ();
    rows = smpl.rows;
    cols = smpl.cols;
    matr = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            matr[i] = new int [cols];
            for (int j = 0; j < cols; j++)
                matr[i][j] = 0;
        }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matr[i][j] = smpl.matr[i][j];
   return *this;
}

int Matrix::operator == (const Matrix& smpl) const
{
    if ((rows != smpl.rows) | (cols != smpl.cols))
        return 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matr[i][j] != smpl.matr[i][j])
                return 0;
    return 1;
}

Matrix operator + (const Matrix& smpl1, const Matrix& smpl2)
{
    Matrix res(smpl1.rows, smpl1.cols);
    if ((smpl1.rows != smpl2.rows) | (smpl1.cols != smpl2.cols))
        return res;
    for (int i = 0; i < res.rows; i++)
        for (int j = 0; j < res.cols; j++)
            res.matr[i][j] = smpl1.matr[i][j] + smpl2.matr[i][j];
    return res;
}

Matrix operator - (const Matrix& smpl1, const Matrix& smpl2)
{
    Matrix res(smpl1.rows, smpl1.cols);
    if ((smpl1.rows != smpl2.rows) | (smpl1.cols != smpl2.cols))
        return res;
    for (int i = 0; i < res.rows; i++)
        for (int j = 0; j < res.cols; j++)
            res.matr[i][j] = smpl1.matr[i][j] - smpl2.matr[i][j];
    return res;
}

Matrix& Matrix::operator += (int val)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matr[i][j] += val;
    return *this;
}

Matrix::Matr_row Matrix::operator [] (int indx)
{
    return Matr_row (matr[indx], this->cols);
}

void Matrix::change (int val, int row, int col)
{
    matr[row][col] = val;
}

void Matrix::printer ()
{
    if (rows & cols)
    {
        printf ("�����: %d ��������: %d\n", rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                printf ("%d ", matr[i][j]);
            printf ("\n");
        }
    }
    else
        printf ("������� �����.\n");
}
