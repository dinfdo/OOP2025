#include "Math.h"
/* va_start example */
#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */
#include <string.h>


int Math::Add(int a, int b)
{
    return a+b;
}

int Math::Add(int a, int b, int c)
{
    return a+b+c;
}

int Math::Add(double a, double b)
{
    return a+b;
}

int Math::Add(double a, double b, double c)
{
    return a+b+c;
}

int Math::Mul(int a, int b)
{
    return a*b;
}

int Math::Mul(int a, int b, int c)
{
    return a*b*c;
}

int Math::Mul(double a, double b)
{
    return a*b;
}

int Math::Mul(double a, double b, double c)
{
    return a*b*c;
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
    if (s1==nullptr||s2==nullptr) return nullptr;
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    char* s3 = new char[l1 + l2 + 1];//sir3 cu lungimea celor 2- alocam in memorie space: new char
    int l3 = l1 + l2 + 1;
    strcpy_s(s3,l3, s1);
    strcat_s(s3,l3, s2);//concatenarea efectiva
    return s3;
}
