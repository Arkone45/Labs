#include "1.4.2.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

void reader (float R[Rmax], int Rm, string R_name)
{
	fin.open(R_name);
	for (int i = 0; i < Rm; i++)
    {
        fin >> R[i];
    }
    fin.close();
}

void printer (float R[Rmax], int Rm)
{
    for (int i = 0; i < Rm; i++)
    {
        fout << R[i];
        fout << " ";
    }
    fout << "\n";
}

float counter (float R[Rmax], int Rm, float t)
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

