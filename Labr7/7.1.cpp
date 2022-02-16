extern "C" __declspec(dllimort) void String_to_words (char *source, char *dest);

#include "Libr7\StringDll.h"
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <clocale>

int main(int argc, char* argv[])
{
    FILE *inp, *outp;
    char str[256], res[256];
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (argc < 2)
    {
        printf ("Недостаточно параметров.\n");
        exit (EXIT_FAILURE);
    }
    if ((inp = fopen (argv[1], "r")) == NULL)
    {
        printf ("Невозможно открыть файл %s.\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    fgets (str, 256, inp);
    fclose (inp);
    String_to_words (str, res);
    if ((outp = fopen (argv[2], "w")) == NULL)
    {
        printf ("Невозможно открыть файл %s.\n", argv[2]);
        exit (EXIT_FAILURE);
    }
    fprintf (outp, "Новая строка: %s\n", res);
    fclose (outp);
    return 0;
}
