/*******************
* ФИО: Шамин А.С   *
* Дата: 13.10.2026 *
* Группа: ПИ-261   *
********************/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Данные для расчета
    const double T0 = 288.15;
    const double p0 = 101325.0;
    const double h1 = 11000.0;
    const double b = 0.0065;
    const double M = 0.02897;
    const double R = 8.314;
    const double g = 9.81;

    // Значения на высоте 11 км
    double T1 = T0 - b * h1;
    double p1 = p0 * pow(T1 / T0, M * g / (R * b));

    // Высоты, для которых нужно найти параметры атмосферы
    int heights[] = { 0, 3, 6, 9, 11, 13, 16, 20 };

    cout << fixed << setprecision(6);
    cout << "Height (km)  Temperature (K)  Pressure (kPa)  Density (kg/m^3)" << endl;

    for (int i = 0; i < 8; i++) {
        double h = heights[i] * 1000.0;
        double T, p, rho;

        // Выбираем формулы в зависимости от высоты
        if (h <= h1) {
            T = T0 - b * h;
            p = p0 * pow(T / T0, M * g / (R * b));
        }
        else {
            T = T1;
            p = p1 * exp(-M * g * (h - h1) / (R * T1));
        }

        // Рассчитываем плотность воздуха
        rho = M * p / (R * T);

        cout << setw(10) << heights[i]
            << setw(17) << T
            << setw(17) << p / 1000.0
            << setw(19) << rho << endl;
    }

    return 0;
}