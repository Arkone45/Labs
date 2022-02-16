#include <iostream>
#include <clocale>
#include <windows.h>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

const int Rmax = 50;

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

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	string Aname, Bname, Cname;
    int Am, Bm, Cm;
    float A[Rmax], B[Rmax], C[Rmax];
    float x, t;
    float Asum, Bsum, Csum;
    cout << "Ввелите число: ";
	cin >> t;
	cout << "Введите максимальное количество эдементов в первом массиве: ";
	cin >> Am;
	cout << "Введите максимальное количество эдементов во втором массиве: ";
	cin >> Bm;
	cout << "Введите максимальное количество эдементов в третьем массиве: ";
	cin >> Cm;
    reader (A, Am, argv[1]);
    reader (B, Bm, argv[2]);
    reader (C, Cm, argv[3]);
    //||||||||||||||||||||||||||||||||||||
    fout.open(argv[4]);
    fout << "Входные данные: \n";
    printer (A, Am);
    printer (B, Bm);
    printer (C, Cm);
    //||||||||||||||||||||||||||||||||||||||||
    Asum = counter (A, Am, t);
    Bsum = counter (B, Bm, t);
    Csum = counter (C, Cm, t);
    //||||||||||||||||||||||||||||||||||||||||||
    if ((Asum == Bsum) & (Bsum == Csum) & (Asum == 0))
    {
    	fout << "Ни в одном из трёх массивов нет элементов, больших заданного числа.\n";
    }
    else if ((Asum != 0) & (Bsum != 0) & (Csum != 0))
    {
        fout << "Во всех трёх массивах совпадает среднее арифметическое элементов, больших заданного числа.\n";
	}
	else
	{
		if (Asum == Bsum)
	    {
	        fout << "В первом и втором массивах совпадает среднее арифметическое элементов, больших заданного числа.\n";
	    }
		else if (Bsum == Csum)
	    {
	        fout << "Во втором и третьем массивах совпадает среднее арифметическое элементов, больших заданного числа.\n";
	    }
	    else if (Asum == Csum)
	    {
	        fout << "В первом и третьем массивах совпадает среднее арифметическое элементов, больших заданного числа.\n";
	    }
	    else if (Asum > Bsum)
	    {
			if ((Bsum > Csum) | (Csum < Asum))
	    	{
	    		fout << "В первом массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n";
	    	}
	    	else
	    	{
	    		fout << "В третьем массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n";
			}
		}
		else
		{
			if ((Asum > Csum) | (Csum < Bsum))
	    	{
	    	    fout << "Во втором массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n";
	    	}
	    	else
	    	{
	    		fout << "В третьем массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n";
			}
		}
    }
    fout.close();
    system ("pause");
    return 0;
}
