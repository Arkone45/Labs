#ifndef mod
#define mod
#include <fstream>
#include <iostream>

using namespace std;

const int Rmax = 50;

void reader (float *(&R), int Rm, char *R_name);
void printer (float *R, int Rm, FILE *fname);
float counter (float *R, int Rm, float t);

#endif /* mod */
