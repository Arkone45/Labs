#include <windows.h>
#include <clocale>
#include <stdio.h>
#include "6.h"


int main()
{
    int n, p, x;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    printf ("¬ведите количество измен€емых битов: ");
    scanf ("%d", &n);
    printf ("¬ведите позицию изменени€: ");
    scanf ("%d", &p);
    printf ("¬ведите измен€емое число: ");
    scanf ("%d", &x);
    printer (x);
    x = bit_changer (x, n, p);
    printer (x);
}
