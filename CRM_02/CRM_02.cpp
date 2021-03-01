#include <iomanip>
#include <windows.h>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double AMount, amount;
	double comp = 0;
	double r[4], Xm[4];
	system("color E0"); //колір консолі
	SetConsoleCP(1251);   //налаштування української мови
	SetConsoleOutputCP(1251); 

	amount = 6;
	AMount = pow(10, -1 * amount);
	double Mat[4][5] = {
	{3.81, 0.25, 1.28, 1.75, 4.21},
	{2.25, 1.32, 5.58, 0.49, 7.47},
	{5.31, 7.28, 0.98, 1.04, 2.38},
	{10.39, 2.45, 3.35, 2.28, 11.48}
	};
	double newMat[4][5] = {
    {3.81, 0.25, 1.28, 1.75, 4.21},
	{2.25, 1.32, 5.58, 0.49, 7.47},
	{5.31, 7.28, 0.98, 1.04, 2.38},
	{10.39, 2.45, 3.35, 2.28, 11.48}
	};
	bool b = true;
	double tmp;
	int i, j = 0;
	cout << "___________________________________________________" << endl;
	cout << endl << "	Наша матриця:" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << setw(9) << Mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "___________________________________________________" << endl;
	cout << endl << "	Система:" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << "	" << Mat[i][j] << "*x" << j + 1;
			if (j == 3)
			{
				cout << " = " << Mat[i][4] << endl;
			}
			else
			{
				cout << " + ";
			}
		}
	}

	double chang;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << endl << " Приведення системи  до еквівалентної системи з трикутною матрицею :" << endl;
	for (i = 0; i < 4; i++)
	{
		tmp = Mat[i][i];
		for (int j = 4; j >= i; j--)
			Mat[i][j] /= tmp;
		for (int j = i + 1; j < 4; j++)
		{
			tmp = Mat[j][i];
			for (int k = 4; k >= i; k--)
				Mat[j][k] -= tmp * Mat[i][k];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		chang = Mat[i][i];
		for (int j = 0; j < 5; j++)
		{
			Mat[i][j] = Mat[i][j] / chang;
			cout << setw(9) << Mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << endl << "	Вибираємо головний елемент x1:" << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << Mat[i][i] << "	x" << i + 1 << " = ";
		for (int j = 0; j < 5; j++)
		{
			if (i != j)
			{
				if (j != 4)
				{
					cout << -Mat[i][j] << "	x" << j + 1;
				}
				else
				{
					cout << " + " << Mat[i][j] << "x";
				}
			}
		}
		cout << endl;
	}

	double vect[4];
	for (int i = 0; i < 4; i++)
	{
		vect[i] = Mat[i][4];
	}
	int n = 0;
	while (b)
	{
		n++;
		cout << endl << " _____________________________" << "Дія №: " << n << " _____________________________" << endl;
		cout << endl << "		Вектор b:" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << "	(" << vect[i] << ")" << endl;
		}
		double second[4];
		for (int i = 0; i < 4; i++) second[i] = 0;
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << endl << "	Після перетворення вектора b:" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << Mat[i][i] << "	x" << i + 1 << " = ";
			for (int j = 0; j < 5; j++)
			{
				if (i != j)
				{
					if (j != 4)
					{
						if (Mat[i][j] * vect[j] > 0)
						{

							cout << " - (" << Mat[i][j] << ") * (" << vect[j] << ")";
						}
						else
						{
							cout << " + (" << Mat[i][j] << ") * (" << vect[j] * (-1) << ")";
						}

					}
					else
					{
						cout << " + (" << Mat[i][j] << ")";
					}
				}
			}
			cout << endl;
		}
		cout << "___________________________________________________________" << endl;
		cout << endl << "" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << Mat[i][i] << "	x" << i + 1 << " = ";
			for (int j = 0; j < 5; j++)
			{
				if (i != j)
				{
					if (j != 4)
					{
						if (Mat[i][j] * vect[j] > 0)
						{
							cout << " (" << Mat[i][j] * (-1) * vect[j] << ") ";
							second[i] += -1 * Mat[i][j] * vect[j];
						}
						else
						{
							cout << " + (" << Mat[i][j] * (-1) * vect[j] << ")";
							second[i] += -1 * Mat[i][j] * vect[j];
						}
					}
					else
					{
						cout << " + (" << Mat[i][j] << ")";
						second[i] += Mat[i][j];
					}
				}
			}
			cout << endl;
		}

		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << endl << "	Результат:" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << "	x" << i + 1 << " = " << round(second[i] * 1000000) / 1000000 << endl;
			vect[i] = second[i];
		}
		/////////////
		if (comp != 0)
		{
			cout << "___________________________________________________________" << endl;
			cout << "	Порівнюємо з попередньою ітерацією:  " << "|" << round(comp * 10000) / 10000 << "- (" << round(second[3] * 10000) / 10000 << ")|=" << round(abs(comp - second[3]) * 10000) / 10000 << endl;
			if (abs(comp - second[3]) < AMount)
			{
				b = false;
			}
		}
		comp = second[3];
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << "	Вектор нев'язки\n";
		cout << endl << "	r = {";
		for (int i = 0; i < 4; i++)
		{
			r[i] = newMat[i][4];
			for (int j = 0; j < 4; j++)
			{
				r[i] -= newMat[i][j] * second[j];
			}
			cout << round(r[i] * 1000) / 1000 << " ";
		}
		cout << "}" << endl;

	}
	system("pause");
	return 0;
}
