#include <windows.h>
#include <iostream>
#include <clocale>
#include "12.2.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    float val, y;
    UList A;
    UDeq<float> B, C, D;
    ifstream ifs1(argv[1]);
    ifs1 >> A;
    ifs1.close();
    cout << "Содержимое файла со списком:\n" << A << "\n";
    if (isalpha(A.get_max()))
    {
        Node<char> *cur = A.get_first();
        char x;
        while (cur != nullptr)
        {
            x = get_value(cur);
            cur = get_next(cur);
            if (ispunct(x))
                A.remove_item (x);
        }
    }
    cout << "Изменённый список:\n" << A << "\n";
    ifstream ifs2(argv[2]);
    ifs2 >> B;
    ifs2.close();
    cout << "Содержимое файла с очередью:\n" << B << "\n";
    cin.tie(&cout);
    cout << "Введите число для разделения очереди: ";
    cin >> val;
    cin.tie(0);
    while (!B.isempty())
    {
        y = B.take_first();
        cout << y << "\n";
        if (y > val)
            C.add_last (y);
        else
            D.add_last (y);
    }
    cout << "Очередь с числами, большими заданного числа:\n" << C << "\n";
    cout << "Очередь с числами, меньшими либо равными заданному числу:\n" << D << "\n";
    return 0;
}
