#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <clocale>
#include "E:\���� �� ����� (�)\2 ����\Labr6\6.2.cpp"

int main ()
{
    int n, p, x, checks, a, b;
    unsigned mask = 1;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand (time(NULL));
    printf ("������� ���������� ��������: ");
    scanf ("%d", &checks);
    for (int i = 1; i <= checks; i++)
    {
        n = 3;//rand() % 32;
        p = rand() % 31;
        x = rand() % LONG_MAX;
        printf ("\n���� �������� �%d:\nn = %d\np = %d\n", i, n, p);
        printer (x);
        b = x;
        a = bit_changer (x, n, p);
        for (int j = p; (j >= 0) && ((j >= p - n) | (p == 0)); j--)
        {
            mask = 1;
            b |= (mask << j);
        }
        printf ("����������� �������:\n");
        printer (a);
        printf ("����������� �������:\n");
        printer (b);
        if (b == a)
            printf ("\n������� �������� ���������.\n");
        else
        {
            printf ("\n������� �������� �����������.\n");
            return -1;
        }
    }
    return 0;
}
