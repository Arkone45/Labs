#include "1.4.2.h"
#include <iostream>
#include <fstream>

void reader (float *(&R), int Rm, char *R_name)
{
    FILE *fin;
	fin = fopen(R_name, "r");
	R = new float [Rm];
	for (int i = 0; i < Rm; i++)
    {
        fscanf(fin, "%g", &R[i]);
    }
    fclose(fin);
}

void printer (float *R, int Rm, FILE *fout)
{
    for (int i = 0; i < Rm; i++)
    {
        fprintf(fout, "%g ", R[i]);
    }
    fprintf(fout,"\n");
}

float counter (float *R, int Rm, float t)
{
	int Rnum = 0;
	float Rsum = 0;
    for (int i = 0; i < Rm; i++)
    {
        if (t < R[i])
        {
            Rsum += R[i];
            Rnum += 1;
        }
    }
    if (Rnum > 0)
    {
		Rsum /= Rnum;
	}
    else
    {
    	Rsum = 0;
	}
	return Rsum;
}

