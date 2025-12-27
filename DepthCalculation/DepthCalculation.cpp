// PodborH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// Объявляем используемые переменные и задаём им начальные значения
	double w = 0.0;
	double C = 0.0;
	double R = 0.0;
	double i = 0.0;
	double m = 0.0;
	double b = 0.0;
	double X = 0.0;
	double Qz = 0.0;
	double n = 0.0;

	// Объявляем искомые переменные и задаём им начальные значения
	double Qr = 0.0;
	double h = 0.0;

	// Вводим данные для уклона дна и валов i, коэффициента заложения откоса m, ширины по дну b
	cout << "Slope of the bottom and shafts 'i' = ";
	cin >> i;
	cout << "Slope coefficient 'm' = ";
	cin >> m;
	cout << "Bottom width 'b', m = ";
	cin >> b;
	cout << "Roughness coefficient 'n' = ";
	cin >> n;

	// Задаём расход воды Qz
	cout << "Water consumption 'Q', m^3/sec. = ";
	cin >> Qz;

	// Начинаем подбор глубины наполнения h
	for (; Qr <= Qz; h += 0.0001) {

		//cout << "h = " << h << "\n";

		// Площадь поперечного сечения 𝜔
		w = (b + m * h) * h;

		// Смоченный периметр 𝜒
		X = b + 2.0 * h * sqrt(1.0 + pow(m, 2.0));

		// Гидравлический радиус R
		R = w / X;

		// Коэффициент Шези C
		C = (1 / n) * pow(R, 1.0 / 6.0);

		// Расчётный расход воды Qr
		Qr = w * C * sqrt(R * i);

		//cout << "Qr = " << Qr << "\n";
	}

	// Выводим результат подбора
	cout << "Cross-sectional area 'w' = " << w << "\n";
	cout << "Wetted perimeter 'X' = " << X << "\n";
	cout << "Hydraulic radius 'R' = " << R << "\n";
	cout << "Chezy coefficient 'C' = " << C << "\n";
	cout << "Q calculated = " << Qr << " = Q given = " << Qz << "\n";
	cout << "Filling depth 'h' = " << h << " meters" << "\n";

	return 0;
}
