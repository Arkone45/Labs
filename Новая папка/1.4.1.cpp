#include <iostream>
#include <clocale>
#include <windows.h>
#include <fstream>
#include "1.4.2.h"

using namespace std;

ifstream fin;
ofstream fout;

//void reader (float R[Rmax], int Rm, string R_name);
//void printer (float R[Rmax], int Rm);
//float counter (float R[Rmax], int Rm, float t);


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
    cout << "������� �����: ";
	cin >> t;
	cout << "������� ������������ ���������� ��������� � ������ �������: ";
	cin >> Am;
	cout << "������� ������������ ���������� ��������� �� ������ �������: ";
	cin >> Bm;
	cout << "������� ������������ ���������� ��������� � ������� �������: ";
	cin >> Cm;
    reader (A, Am, argv[1]);
    reader (B, Bm, argv[2]);
    reader (C, Cm, argv[3]);
    //||||||||||||||||||||||||||||||||||||
    fout.open(argv[4]);
    fout << "������� ������: \n";
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
    	fout << "�� � ����� �� ��� �������� ��� ���������, ������� ��������� �����.\n";
    }
    else if ((Asum != 0) & (Bsum != 0) & (Csum != 0))
    {
        fout << "�� ���� ��� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	}
	else
	{
		if (Asum == Bsum)
	    {
	        fout << "� ������ � ������ �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	    }
		else if (Bsum == Csum)
	    {
	        fout << "�� ������ � ������� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	    }
	    else if (Asum == Csum)
	    {
	        fout << "� ������ � ������� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	    }
	    else if (Asum > Bsum)
	    {
			if ((Bsum > Csum) | (Csum < Asum))
	    	{
	    		fout << "� ������ ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
	    	}
	    	else
	    	{
	    		fout << "� ������� ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
			}
		}
		else
		{
			if ((Asum > Csum) | (Csum < Bsum))
	    	{
	    	    fout << "�� ������ ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
	    	}
	    	else
	    	{
	    		fout << "� ������� ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
			}
		}
    }
    fout.close();
    system ("pause");
    return 0;
}
