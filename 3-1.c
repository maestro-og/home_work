#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя, иначе выводит ошибку
 */
double GETnum(const char *string);

/**
 * @brief вычисляет ординату
 * @param x - абсцисса (должна входить в ООФ: x >= 0)
 * @return значение ординаты
 */
double y(const double x);

/**
 * @brief проверка параметров: x_start входит в ООФ (x >= 0),
 *        начало не больше конца, шаг больше 0
 * @param x_start - начальная абсцисса
 * @param x_end - конечная абсцисса
 * @param x_step - расстояние между соседними абсциссами
 */
void Check_param(const double x_start, const double x_end, const double x_step);

/**
 * @brief табулирование функции
 * @param x_start - начальная абсцисса
 * @param x_end - конечная абсцисса
 * @param x_step - расстояние между соседними абсциссами
 */
void Tabulation(const double x_start, const double x_end, const double x_step);

/**
 * @brief точка входа в программу
 * @return возвращает 0
 */
int main() {

  const double x_start = GETnum("Point start: ");
  const double x_end = GETnum("Point end: ");
  const double x_step = GETnum("Step: ");

  Check_param(x_start, x_end, x_step);
  Tabulation(x_start, x_end, x_step);

  return 0;
}

double y(const double x) {
  return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

void Check_param(const double x_start, const double x_end, const double x_step) {
  if (x_start < 0) {
    printf("Error: x must be >= 0\n");
    exit(1);
  }
  if (x_step <= 0 || x_start > x_end) {
    printf("Error\n");
    exit(1);
  }
}

void Tabulation(const double x_start, const double x_end, const double x_step) {
  for (double x = x_start; x <= x_end + (x_step / 2); x += x_step) {
    printf("x = %.3f  y = %.4f\n", x, y(x));
  }
}

double GETnum( const char *string) {
  printf("%s",string);
  double num = 0.0;
  if (scanf("%lf", &num) != 1) {
    printf("Error\n");
    exit(1);
  }
  return num;
}
