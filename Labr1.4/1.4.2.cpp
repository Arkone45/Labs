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
    printf ("Ввелите число: ");
	scanf ("%f", &t);
	printf ("Введите максимальное количество эдементов в первом массиве: ");
	scanf ("%d", &Am);
	printf ("Введите максимальное количество эдементов во втором массиве: ");
	scanf ("%d", &Bm);
	printf ("Введите максимальное количество эдементов в третьем массиве: ");
	scanf ("%d", &Cm);
    reader (A, Am, argv[1]);
    reader (B, Bm, argv[2]);
    reader (C, Cm, argv[3]);
    //--------------------------------------------
    out = fopen(argv[4], "w");
    fprintf(out,"Входные данные: \n");
    printer (A, Am, out);
    printer (B, Bm, out);
    printer (C, Cm, out);
    //-------------------------------------------------
    Asum = counter (A, Am, t);
    Bsum = counter (B, Bm, t);
    Csum = counter (C, Cm, t);
    //--------------------------------------------------------------
    if ((Asum == Bsum) & (Bsum == Csum) & (Asum == 0))
    	fprintf(out, "Ни в одном из трёх массивов нет элементов, больших заданного числа.\n");
    else if ((Asum != 0) & (Bsum != 0) & (Csum != 0) & (Asum == Bsum == Csum))
        fprintf(out, "Во всех трёх массивах совпадает среднее арифметическое элементов, больших заданного числа.\n");
	else
	{
		if ((Asum == Bsum) & (Asum > Csum))
	        fprintf(out, "В первом и втором массивах совпадает среднее арифметическое элементов, больших заданного числа.\n");
		else if ((Bsum == Csum) & (Bsum > Asum))
	        fprintf(out, "Во втором и третьем массивах совпадает среднее арифметическое элементов, больших заданного числа.\n");
	    else if ((Asum == Csum) & (Asum > Bsum))
	        fprintf(out, "В первом и третьем массивах совпадает среднее арифметическое элементов, больших заданного числа.\n");
	    else if (Asum > Bsum)
	    {
			if ((Bsum > Csum) | (Csum < Asum))
	    		fprintf(out,"В первом массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n");
	    	else
	    		fprintf(out, "В третьем массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n");
		}
		else
		{
			if ((Asum > Csum) | (Csum < Bsum))
	    	    fprintf(out, "Во втором массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n");
	    	else
	    		fprintf(out, "В третьем массиве наибольшее среднее арифметическое элементов, больших заданного числа.\n");
		}
    }
    fclose(out);
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
