#include <windows.h>
#include <clocale>
#include "6.h"

int bit_changer (int x, int n, int p)
{
    unsigned mask = 1;
    if ((0 > p) | (p >= 32))
    {
        printf ("Устанавливаемый бит за пределами типа int.\n");
        return -1;
    }
    for (int i = 1; (i <= n) && (i <= p); i++)
    {
        mask <<= 1;
        mask |= 1;
    }
    if (p - n > 0)
        mask <<= p - n;
    return x | mask;
}

void printer (int x)
{
    boolean *bin;
    int i = 0;
    printf ("DEC: %d\n", x);
    printf ("HEX: %X\n", x);
    bin = new boolean[32];
    while ((i < 32) && x > 0)
    {
        bin[i] = x%2;
        x /= 2;
        i++;
    }
    printf ("BIN: ");
    for (int j = i-1; j >= 0; j--)
    {
        printf ("%d", bin[j]);
    }
    printf ("\n");
    delete (bin);
}
