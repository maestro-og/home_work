#include <stdio.h>
#include <math.h>

/**
 * @brief рассчивает прееменную b
 * @param a - первая сторона прямоугольника
 * @param n - коэффициент
 * @return расчитанное значение
 */
double B( const double a, const double n);

/**
 * @brief точка входа в программу
 * @return значение 0, если программа выполнена корректно
 */
int main() {
  double a(), n();

  printf("Введите значение первой стороны: ");
  scanf("%lf", &a);
  printf("Введите значение коэффициента (%%): ");
  scanf("%lf", &n);

  n /= 100;

  double perimetr = (a + B(a, n)) * 2;
  double area = a * B(a, n);

  printf("Площадь прямоугольника = %lf\n", area);
  printf("Периметр прямоугольника = %lf\n", perimetr);

  return 0;
}

double B(const double a, const double n) {
  return (a * n);
}
