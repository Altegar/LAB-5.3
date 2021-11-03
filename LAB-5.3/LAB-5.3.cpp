// LAB-5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Lab_05_3.cpp
// Сушинський Ігор
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями.
// Варіант 18


#include <iostream>
#include <cmath>

using namespace std;

double f(const double x);

int main()
{
	double tp, tk, z;
	int n;

	cout << "tp = "; cin >> tp;
	cout << "tk = "; cin >> tk;
	cout << "n = "; cin >> n;

	double dt = (tk - tp) / n;

	double t = tp;

	while (t <= tk)
	{
		z = f(1 + 2 * t) + pow(f(f(1) + 2 * f(2 * t)), 2);
		cout << t << " " << z << endl;
		t += dt;
	}

	return 0;
}

double f(const double x)
{
	if (abs(x) >= 1)
		return (sin(x) * sin(x) + sin(x * x)) / (1 + cos(x) * cos(x));
	else
	{
		double S = 0;
		int n = 0;
		double a = 1 / (1 + x * x);
		S = a;
		do
		{
			n++;
			double R = x / (4 * n - 1);
			a *= R;
			S += a;
		} while (n < 6);
		return S;
	}
}