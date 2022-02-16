#ifndef mod
#define mod
#include <fstream>
#include <iostream>

using namespace std;

void reader (float **(&R), int Rn, int Rm, char *R_name);
void matr_printer (float **R, int Rn, int Rm, FILE *fout);
void zero (float **R, int Rn, int Rm, int *(&result));
void multiplication (float **R, int Rn, int Rm, int *zeros, float *(&result));
void mas_printer (float *R, int Rn, FILE *fout);

#endif // mod
