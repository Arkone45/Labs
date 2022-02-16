#ifndef mod
#define mod
#include <fstream>
#include <iostream>

using namespace std;

void reader (float **(&R), int Rn, int Rm, char *R_name);
void matr_printer (float **R, int Rn, int Rm, FILE *fout);
boolean zero (float *R, int Rm);
void multiplication (float **R, int Rn, int Rm, float *(&result));
void mas_printer (float *R, int Rn, FILE *fout);

#endif // mod
