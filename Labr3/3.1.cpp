#include <windows.h>
#include <fstream>
#include <clocale>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "3.h"

using namespace std;

int main(int argc, char* argv[])
{
    int a_num, b_num, n, k;
    float  x[Nmax], y[Nmax];
    FILE *inp, *outp;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //=======================================
    text_to_bin (argv[1], argv[2], &a_num, &b_num, &n);
    printf ("Исходные данные:");
    printer (argv[2]);
    replace_in_bin (argv[2], a_num, b_num);
    printf ("Изменённый файл:");
    printer (argv[2]);
}
