#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

/**
 *ДОП СВЕДЕНИЯ:
 * E = (m*v^2)/2 - формула кинетической энергии
 */

 /**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя , иначе выводит ошибку
 */
double GETvalue();

/**
 * @brief проверяет значение на положительность
 * @param a - проверяемое значение
 */
void Checkparam(const double a);

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
    setlocale(LC_ALL, "Russian");
    printf("Введите значение массы(кг) пули: ");
    double massa = GETvalue();
    Checkparam(massa);

    printf("Введите значение скорости(м/с) пули: ");
    double pace = GETvalue();
    Checkparam(pace);

    printf("Кинетическая энергия = %lf", E(massa, pace));

    return 0;
}

double GETvalue(){
    double value = 0;
    if (!scanf("%lf",&value)){
        printf("Error\n");
        exit(1);
    }
    return value;
}

void Checkparam(const double value){
    if (value <= 0){
        printf("Значение строго положительное\n");
        exit(1);
    }
}

double E(const double massa, const double pace){
    return (massa*pow(pace,2))/2;
}
