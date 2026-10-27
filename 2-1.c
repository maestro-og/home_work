#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя, иначе выводит ошибку
 */
double GETvalue();

/**
 * @brief проверяет значение на положительность
 * @param value - проверяемое значение
 */
void Checkparam(const double value);

/**
 * @brief вычисляет объем шара
 * @param radius - радиус шара
 * @return объем шара
 */
double Volume(const double radius);

/**
 * @brief вычисляет площадь поверхности шара
 * @param radius - радиус шара
 * @return площадь поверхности шара
 */
double Area(const double radius);

/**
 * @brief выбирает формулу в зависимости от выбора пользователя
 * @param choose - 1 (объем) или 2 (площадь поверхности)
 * @param radius - радиус, заданный пользователем
 * @return результат вычисления, при некорректном выборе завершает программу
 */
double Choose(const short choose, const double radius);

/**
 * @brief входная точка
 * @return значение 0, если программа выполнена корректно
 */
int main() {
    setlocale(LC_ALL, "Russian");

    printf("Введи значение радиуса: ");
    const double radius = GETvalue();
    Checkparam(radius);

    printf("Выбери что хочешь вычислить\n"
           "Введите '1' чтобы вычислить Объем шара\n"
           "Введите '2' чтобы вычислить Площадь поверхности шара\n");
    const short choose = (short)GETvalue();

    printf("%lf\n", Choose(choose, radius));

    return 0;
}

double GETvalue() {
    double value = 0;
    if (scanf("%lf", &value) != 1) {
        printf("Error\n");
        exit(1);
    }
    return value;
}

void Checkparam(const double value) {
    if (value <= 0) {
        printf("Корректны только положительные значения\n");
        exit(1);
    }
}

double Volume(const double radius) {
    return 4.0 / 3.0 * M_PI * pow(radius, 3);
}

double Area(const double radius) {
    return 4.0 * M_PI * pow(radius, 2);
}

double Choose(const short choose, const double radius) {
    if (choose == 1) {
        printf("Объем шара = ");
        return Volume(radius);
    }
    if (choose == 2) {
        printf("Площадь поверхности шара = ");
        return Area(radius);
    }
    printf("Ввели некорректное значение\n");
    exit(1);
}
