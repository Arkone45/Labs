#include <windows.h>
#include <fstream>
#include <clocale>
#include "8.h"

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Matrix x (3, 3);
    Matrix y (x, 2);
    Matrix z (9);
    double g;
    x.printer ();
    y.printer ();
    z.printer ();
    y.change (3, 0, 1);
    y.change (3, 1, 1);
    y.change (3, 2, 1);
    y.printer ();
    g = y;
    printf ("Среднее ариметическое матрицы Y: %g\n", g);
    return 0;
}
