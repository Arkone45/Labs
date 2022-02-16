#include <stdio.h>
#include <malloc.h>
#include <exception>
#include <stdexcept>
#include "11.h"


Exeption::Exeption ()
{}

Exeption::~Exeption ()
{}

void Exeption::print_exeption()
{}

Invalid_index::Invalid_index (int i, bool s, Matrix *m) : indx(i), is_str(s), matr_ptr(m)
{}

Matrix* Invalid_index::Get_Mptr()
{
    return matr_ptr;
}

int Invalid_index::GetIndx()
{
    return indx;
}

bool Invalid_index::GetStr()
{
    return is_str;
}

Different_matrices_sizes::Different_matrices_sizes (bool s, const Matrix *m1, const Matrix *m2) : is_sum(s), matr1_ptr(m1), matr2_ptr(m2)
{}

const Matrix* Different_matrices_sizes::Get_Mptr1()
{
    return matr1_ptr;
}

const Matrix* Different_matrices_sizes::Get_Mptr2()
{
    return matr2_ptr;
}

bool Different_matrices_sizes::GetSum()
{
    return is_sum;
}

void Invalid_index::print_exeption()
{
        if (this->GetStr())
        {
            printf ("Попытка доступа к элементу с индексом [%d] за пределами строки матрицы:\n", this->GetIndx());
            this->Get_Mptr()->printer();
        }
        else
        {
            printf ("Попытка доступа к строке с индексом [%d] за пределами столбца матрицы:\n", this->GetIndx());
            this->Get_Mptr()->printer ();
        }
}

void Different_matrices_sizes::print_exeption()
{
        if (this->GetSum())
        {
            printf ("\nПопытка сложения матриц:\n");
            this->Get_Mptr1()->printer();
            this->Get_Mptr2()->printer();
        }
        else
        {
            printf ("\nПопытка вычитаия матриц:\n");
            this->Get_Mptr1()->printer();
            this->Get_Mptr2()->printer();
        }
}


Matrix::Matr_row::Matr_row (Matrix *m, int *r, int l) : matr(m), row(r), len(l)
{}

Matrix::Matr_row::~Matr_row ()
{
    printf ("Уничтожение ряда завершено.\n");
}

int Matrix::Matr_row::operator [] (int indx)
{
    if ((indx < 0) | (indx >= this->len))
        throw Invalid_index (indx, true, this->matr);
    else
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

Matrix& Matrix::operator = (const Matrix &smpl)
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
        throw Different_matrices_sizes (true, &smpl1, &smpl2);
    for (int i = 0; i < res.rows; i++)
        for (int j = 0; j < res.cols; j++)
            res.matr[i][j] = smpl1.matr[i][j] + smpl2.matr[i][j];
    return res;
}

Matrix operator - (const Matrix& smpl1, const Matrix& smpl2)
{
    Matrix res(smpl1.rows, smpl1.cols);
    if ((smpl1.rows != smpl2.rows) | (smpl1.cols != smpl2.cols))
        throw Different_matrices_sizes (false, &smpl1, &smpl2);
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
    if ((indx < 0) | (indx >= this->rows))
        throw Invalid_index (indx, false, this);
    else
        return Matr_row (this, matr[indx], this->cols);
}

void Matrix::change (int val, int row, int col)
{
    matr[row][col] = val;
}

void Matrix::printer () const
{
    if (rows & cols)
    {
        printf ("Строк: %d\nСтолбцов: %d\n", rows, cols);
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
