#ifndef mod
#define mod
#include <fstream>
#include <iostream>

using namespace std;

const int Rmax = 50;

void reader (float R[][Rmax], int Rn, int Rm, char *R_name); //Чтение матрицы из файла
void matr_printer (float R[][Rmax], int Rn, int Rm, FILE *fout); //Вывод матрицы в файл
int matr_has_zero (float R[][Rmax], int Rn, int Rm); //Поиск нулей во всей матрице
void multiplication (float R[][Rmax], int Rn, int Rm, float result[]); //Перемножение ненулевых элеменов в каждой строке
void mas_printer (float R[], int Rn, FILE *fout); //Вывод массива в файл

#endif // mod
