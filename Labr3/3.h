#ifndef mod
#define mod
#include <fstream>
#include <iostream>

using namespace std;

const int Nmax = 100;
const int rec = 3;

void text_to_bin (char *T_name, char *B_name, int *a, int *b, int *n);
void printer (char *fname);
void replace_in_bin (char *B_name, int a, int b);

#endif // mod
