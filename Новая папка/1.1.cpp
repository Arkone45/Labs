#include <iostream>
//#include <clocale>
//#include <windows.h>

using namespace std;

int main()
{
	//setlocale(LC_ALL, "Russian");
	//SetConsoleOutputCP(1251);
    const int Amax = 50, Bmax = 50, Cmax = 50;
    int Am, Bm, Cm;
    int Anum = 0, Bnum = 0, Cnum = 0; 
    float A[Amax], B[Bmax], C[Cmax];
    float x, t;
    float Asum = 0, Bsum = 0, Csum = 0;
    cout << "������� �����: ";
	cin >> t;
	cout << "������� ������������ ���������� ��������� � ������ �������: ";
	cin >> Am;
	cout << "������� ������������ ���������� ��������� �� ������ �������: ";
	cin >> Bm;
	cout << "������� ������������ ���������� ��������� � ������� �������: ";
	cin >> Cm;
    cout << "������� ������ ������: ";
    for (int i = 0; i < Am; i++)
    {
        cin >> x;
        A[i] = x;
    }
    cout << "������� ������ ������: ";
    for (int i = 0; i < Bm; i++)
    {
        cin >> x;
        B[i] = x;
    }
    cout << "������� ������ ������: ";
    for (int i = 0; i < Cm; i++)
    {
        cin >> x;
        C[i] = x;
    }
    //||||||||||||||||||||||||||||||||||||
    for (int i = 0; i < Am; i++)
    {
        if (t < A[i])
        {
            Asum += A[i];
            Anum += 1;
        }
    }
    for (int i = 0; i < Bm; i++)
    {
        if (t < B[i])
        {
            Bsum += B[i];
            Bnum += 1;
        }
    }
    for (int i = 0; i < Cm; i++)
    {
        if (t < C[i])
        {
            Csum += C[i];
            Cnum += 1;
        }
    }
    //|||||||||||||||||||||||||||||||||||||||
	if (Anum > 0)
    {
		Asum /= Anum;
	}
    else
    {
    	Asum = 0;
	}
    if (Bnum > 0)
    {
		Bsum /= Bnum;
	}
    else
    {
    	Bsum = 0;
	}
	if (Cnum > 0)
    {
		Csum /= Cnum;
	}
    else
    {
    	Csum = 0;
	}
    //||||||||||||||||||||||||||||||||||||
    cout << "������� ������: \n";
    for (int i = 0; i < Am; i++)
    {
        cout << A[i];
        cout << " ";
    }
    cout << "\n";
    for (int i = 0; i < Bm; i++)
    {
        cout << B[i];
        cout << " ";
    }
        cout << "\n";
    for (int i = 0; i < Cm; i++)
    {
        cout << C[i];
        cout << " ";
    }
    cout << "\n";
    //||||||||||||||||||||||||||||||||||||||||
    if ((Asum == Bsum) & (Bsum == Csum) & (Asum == 0))
    {
    	cout << "�� � ����� �� ��� �������� ��� ���������, ������� ��������� �����.\n";
    }
    else if ((Asum != 0) & (Bsum != 0) & (Csum != 0))
    {
        cout << "�� ���� ��� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	}
	else
	{
		if (Asum == Bsum)
	    {
	        cout << "� ������ � ������ �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	    }
		else if (Bsum == Csum)
	    {
	        cout << "�� ������ � ������� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	    }
	    else if (Asum == Csum)
	    {
	        cout << "� ������ � ������� �������� ��������� ������� �������������� ���������, ������� ��������� �����.\n";
	    }
	    else if (Asum > Bsum)
	    {
			if ((Bsum > Csum) | (Csum < Asum))
	    	{
	    		cout << "� ������ ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
	    	}
	    	else
	    	{
	    		cout << "� ������� ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
			}
		}
		else
		{
			if ((Asum > Csum) | (Csum < Bsum))
	    	{
	    	    cout << "�� ������ ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
	    	}
	    	else
	    	{
	    		cout << "� ������� ������� ���������� ������� �������������� ���������, ������� ��������� �����.\n";
			}
		}
    }
    system ("pause");
    return 0;
}
