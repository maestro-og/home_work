#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя , иначе выводит ошибку
 */
double GETnum();

/**
 * @brief вычиляет ординату
 * @param x - абсциса
 * @return значение ординаты
 */
double y(const double x);

/**
 * @brief проверка цикла ( начало не будет больше конца и шаг не = 0 )
 * @param x_start - начальная абсцисса
 * @param x_end - конечная абсцисы
 * @param x_step - расстояние между соседними абсцисами
 */
void Check_param(const double x_start, const double x_end, const double x_step);

/**
 * @brief цикл
 * @param x_start - начальная абсцисса
 * @param x_end - конечная абсцисы
 * @param x_step - расстояние между соседними абсцисами
 * @return - возвращает координаты (x,y)
 */
void Tabulation(const double x_start, const double x_end, const double x_step);

/**
 * @brief точка входа в программу
 * @return возвращает 0
 */
int main() {
  printf("Point start: ");
  const double x_start = GETnum();

  printf("Point end: ");
  const double x_end = GETnum();

  printf("Step: ");
  const double x_step = GETnum();

  Check_param(x_start,x_end,x_step);
  Tabulation(x_start,x_end,x_step);

  return 0;

}

double y(const double x) {
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

void Check_param(const double x_start, const double x_end, const double x_step){
  if (x_step <= 0 || x_start > x_end){
    printf("Error\n");
    exit(1);
  }
}

void Tabulation(const double x_start, const double x_end, const double x_step) {
  for (double x = x_start ; x <= x_end + DBL_EPSILON; x += x_step) {
        printf("x = %.3f  y = %.4f\n", x, y(x));
    }
}

double GETnum(){
  double num = 0.0;
  if (scanf("%lf",&num) != 1){
    printf("Error\n");
    exit(1);
  }
  return num;
}

