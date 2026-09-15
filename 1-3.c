#include <stdio.h>
#include <math.h>

/**
 *ДОП СВЕДЕНИЯ:
 * E = (m*v^2)/2 - формула кинетической энергии
 */

/**
 *@brief расчитывает кинетическую энергию
 *@param m - масса пули в килограммах 
 *@param v - скорость пули в метрах/секунду
 *@return расчитанное значение
 */
double E(const double m, const double v);

/**
 *@brief входная точка
 *@return значение 0, если программа выполнена корректно
 */
int main(){
    double m();
    double v();
    printf("Введите значение массы(кг) пули: ");
    scanf("%lf", &m);

    printf("Введите значение скорости(м/с) пули: ");
    scanf("%lf", &v);

    printf("Кинетическая энергия = %lf", E(m, v));

    return 0;
}

double E(const double m, const double v){
    return (m+pow(v,2))/2;
}
