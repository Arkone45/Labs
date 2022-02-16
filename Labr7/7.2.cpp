#include <cstdio>
#include <windows.h>
#include <fstream>
#include <clocale>

typedef void (*LibraryFunction)(char *, char *);

int main(int argc, char* argv[])
{
    FILE *inp, *outp;
    char str[256], res[256];
    HINSTANCE hLib;                        //Идентификатор библиотеки
    LibraryFunction f;

    hLib = LoadLibrary(TEXT("Libr7.dll"));
    if (hLib == NULL)
    {
        printf("Невозможно загрузить библиотеку 'Libr7.dll'!\n");
        exit (EXIT_FAILURE);
    }
    f = (LibraryFunction)GetProcAddress(hLib, "String_to_words");
    if (!f)
        printf("Невозможно найти функцию 'String_to_words'!\n\n");
    else
    {
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
        f (str, res);
        if ((outp = fopen (argv[2], "w")) == NULL)
        {
            printf ("Невозможно открыть файл %s.\n", argv[2]);
            exit (EXIT_FAILURE);
        }
        fprintf (outp, "Новая строка: %s\n", res);
        fclose (outp);
    }
    FreeLibrary(hLib);
}
