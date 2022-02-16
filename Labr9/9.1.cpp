#include <windows.h>
#include <fstream>
#include <clocale>
#include "9.h"

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Matrix x (3, 3);
    Matrix y (x, 2);
    Matrix z (9);
    Matrix v (x, 3);
    double g;
    x.printer ();
    y.printer ();
    z.printer ();
    y.change (3, 0, 1);
    y.change (5, 1, 1);
    y.change (3, 2, 1);
    y.printer ();
    g = y;
    printf ("Среднее ариметическое матрицы Y: %g\n", g);
    printf ("%d\n", y[1][1]);
    y.change (7, 0, 0);
    y = y;
    x = y;
    x.printer ();
    y.printer ();
    v.printer ();
    if (x == y)
    {
        x = y + v;
        x.printer ();
        x = x - v - v;
        x.printer ();
    }
    x += -1;
    x.printer ();
    return 0;
}
