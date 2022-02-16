#ifndef mod
#define mod
#include <fstream>
#include <iostream>

using namespace std;

const int Rmax = 50;

void reader (float R[][Rmax], int Rn, int Rm, char *R_name);
void matr_printer (float R[][Rmax], int Rn, int Rm, FILE *fout);
int row_has_zero (float R[], int Rm);
int matr_has_zero (float R[][Rmax], int Rn, int Rm);
void multiplication (float R[][Rmax], int Rn, int Rm, float result[]);
void mas_printer (float R[], int Rn, FILE *fout);

#endif // mod
