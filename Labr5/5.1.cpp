#include <windows.h>
#include <fstream>
#include <clocale>
#include <iostream>


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
}
