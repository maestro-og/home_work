#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int getInt(const char* message);
double getValue(const char* message);
void checkPositive(const int n);
void checkEpsilon(const double e);
double sumN(const int n);
double sumE(const double e);
double getCoef(const int i);

int main(){
    int n = getInt("Enter n: ");
    checkPositive(n);
    double e = getValue("Enter e: ");
    checkEpsilon(e);
    printf("Sum of %d elements is: %.5lf\n", n, sumN(n));
    printf("Sum of elements not less than %lf is: %.5lf\n", e, sumE(e));
    return 0;
}

double getValue(const char* message){
    if (message != NULL){
        printf("%s\n", message);
    }
    double value = 0;
    if (scanf("%lf", &value) != 1){
        printf("Input error");
        exit(1);
    }
    return value;
}

int getInt(const char* message){
    if (message != NULL){
        printf("%s\n", message);
    }
    int value = 0;
    if (scanf("%d", &value) != 1){
        printf("Input error");
        exit(1);
    }
    return value;
}

void checkPositive(const int n){
    if (n <= 0){
        printf("Error, n have to be positive\n");
        exit(1);
    }
}

void checkEpsilon(const double e){
    if (e <= 0){
        printf("Error, e have to be positive\n");
        exit(1);
    }
}


double getCoef(const int i){
    return -1.0 / ((i + 3.0) * (i + 4.0));
}


double sumN(const int n){
    double a = 1.0 / 12;
    double result = a;
    for (int i = 0; i < n; i++){
        a *= getCoef(i);
        result += a;
    }
    return result;
}


double sumE(const double e){
    double a = 1.0 / 12;
    double result = 0;
    for (int i = 0; fabs(a) >= e - DBL_EPSILON; i++){
        result += a;
        a *= getCoef(i);
    }
    return result;
}
