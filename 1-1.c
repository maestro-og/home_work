#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/* 
* @brief рассчет функции А по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @return рассчитанное занчение
*/
double GETA(const double x, const double y);

/*
* @brief рассчет функции B по заданной формуле
* @param z - значение параметра z
* @return рассчитанное занчение
*/
double GETB(const double z);

/*
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main() {
  const double x = 1.426;
  const double y = -1.22;
  const double z = 3.5;
  printf("a = %lf\n", GETA(x,y));
  printf("b = %lf\n", GETB(z));

  return 0;
}

double GETA(const double x, const double y) {
  return (2 * cos(x - (6 / M_PI))) / (0.5 + pow(sin(y), 2));
}

double GETB(const double z) {
  return 1 + (pow(z, 2) / (3 + (pow(z, 2) / 5)));
}
