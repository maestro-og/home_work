
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя , иначе выводит ошибку
 */
double GETvalue();

/**
 * @brief проверяет значеие на положительность
 * @param a - проверяемое значение
 */
void Checkparam(const double a);
/**
 * @brief рассчивает вторую сторону
 * @param a - первая сторона прямоугольника
 * @param n - коэффициент
 * @return расчитанное значение
 */
double Side2(const double a, const double n);

 /**
  * @brief вычисляет периметр прямоугольника
  * @param a - первая сторона
  * @param b - вторая сторона
  * @return значение периметра
  */
double Perimetr(const double a, const double b);

/**
 * @brief вычисляет площадь прямоугольника
 * @param a - первая сторона
 * @param b - вторая сторона
 * @return значение площади
 */
double Area(const double a, const double b);

/**
 * @brief точка входа в программу
 * @return значение 0, если программа выполнена корректно
 */
int main() {
    setlocale(LC_ALL, "Russian");

    printf("Введите значение первой стороны: ");
    double side1 = GETvalue();
    Checkparam(side1);

    printf("Введите значение коэффициента (%%): ");
    double kef = GETvalue();
    Checkparam(kef);

    kef /= 100;

    printf("Площадь прямоугольника = %lf\n", Area(side1, Side2(side1, kef)));
    printf("Периметр прямоугольника = %lf\n", Perimetr(side1, Side2(side1, kef)));

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

void Checkparam(const double a){
    if (a <= 0){
        printf("Значение строго положительное\n");
        exit(1);
    }
}

double Side2(const double a, const double n) {
    return (a * n);
}

double Perimetr(const double a, const double b) {
    return (a + b) * 2;
}

double Area(const double a, const double b) {
    return a * b;
}
