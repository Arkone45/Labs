#include <iostream>
#include <clocale>
#include <windows.h>
#include <fstream>
#include "1.4.2.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	string Aname, Bname, Cname;
    int Am, Bm, Cm;
    float *A, *B, *C;
    float t;
    float Asum, Bsum, Csum;
    FILE *out;
    printf ("������� �����: ");
	scanf ("%f", &t);
	printf ("������� ������������ ���������� ��������� � ������ �������: ");
	scanf ("%d", &Am);
	printf ("������� ������������ ���������� ��������� �� ������ �������: ");
	scanf ("%d", &Bm);
	printf ("������� ������������ ���������� ��������� � ������� �������: ");
	scanf ("%d", &Cm);
    reader (A, Am, argv[1]);
    reader (B, Bm, argv[2]);
    reader (C, Cm, argv[3]);
    //--------------------------------------------
    out = fopen(argv[4], "w");
    fprintf(out,"������� ������: \n");
    printer (A, Am, out);
    printer (B, Bm, out);
    printer (C, Cm, out);
    //-------------------------------------------------
    Asum = counter (A, Am, t);
    Bsum = counter (B, Bm, t);
    Csum = counter (C, Cm, t);
    //--------------------------------------------------------------
    if ((Asum == Bsum) & (Bsum == Csum) & (Asum == 0))
    	fprintf(out, "�� � ����� �� ��� �������� ��� ���������, ������� ��������� �����.\n");
    else if ((Asum != 0) & (Bsum != 0) & (Csum != 0) & (Asum == Bsum == Csum))
        fprintf(out, "�� ���� ��� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n");
	else
	{
		if ((Asum == Bsum) & (Asum > Csum))
	        fprintf(out, "� ������ � ������ �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n");
		else if ((Bsum == Csum) & (Bsum > Asum))
	        fprintf(out, "�� ������ � ������� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n");
	    else if ((Asum == Csum) & (Asum > Bsum))
	        fprintf(out, "� ������ � ������� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n");
	    else if (Asum > Bsum)
	    {
			if ((Bsum > Csum) | (Csum < Asum))
	    		fprintf(out,"� ������ ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n");
	    	else
	    		fprintf(out, "� ������� ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n");
		}
		else
		{
			if ((Asum > Csum) | (Csum < Bsum))
	    	    fprintf(out, "�� ������ ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n");
	    	else
	    		fprintf(out, "� ������� ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n");
		}
    }
    fclose(out);
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
