#include <windows.h>
#include <fstream>
#include <clocale>

int main(int argc, char* argv[])
{
    FILE *inp, *outp;
    char str1[256], str2[256], temp[256];
    int j = 0;
    boolean doubles = false;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if ((inp = fopen (argv[1], "r")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    fgets (str1, 256, inp);
    fclose (inp);
    temp[0] = '\0';
    str2[0] = '\0';
    for (int i = 0; str1[i]; i++)
    {
        if (isalnum ((int)str1[i]))
        {
            if (strchr(temp, str1[i]))
                doubles = true;
            temp[j] = str1[i];
            temp[j+1] = '\0';
            j++;
        }
        else
        {
            if ((temp[0] != '\0') && !doubles)
            {
                temp[j] = ' ';
                temp[j+1] = '\0';
                strcat (str2, (const char*)&temp);
            }
            j = 0;
            temp[0] = '\0';
            doubles = false;
        }
    }
    if (temp[0] != '\0')
        strcat (str2, (const char*)&temp);
    if ((outp = fopen (argv[2], "w")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", argv[2]);
        exit (EXIT_FAILURE);
    }
    fprintf (outp, "Новая строка: %s\n", str2);
    fclose (outp);
}
