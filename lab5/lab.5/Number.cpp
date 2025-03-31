#include "Number.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int ConvertToBase10(const char* value, int base) {
    int result = 0;
    int length = strlen(value);
    for (int i = 0; i < length; ++i) {
        char digit = value[i];
        int num = (digit >= '0' && digit <= '9') ? digit - '0' : digit - 'A' + 10;
        result = result * base + num;
    }
    return result;
}

char* ConvertFromBase10(int num, int base) {
    if (num == 0) {
        char* result = new char[2] {'0', '\0'};
        return result;
    }

    int temp = num, digits = 0;
    while (temp > 0) {
        ++digits;
        temp /= base;
    }

    char* result = new char[digits + 1];
    result[digits] = '\0';

    while (num > 0) {
        int remainder = num % base;
        result[--digits] = (remainder < 10) ? '0' + remainder : 'A' + (remainder - 10);
        num /= base;
    }
    return result;
}

Number::Number(const char* val, int b) { //constructor char
    base = b;
    value = new char[strlen(val) + 1];
    strcpy_s(value, strlen(val) + 1, val);
}

Number::Number(int num, int b) { //constr din int
    base = b;
    char* temp = ConvertFromBase10(num, b);
    value = new char[strlen(temp) + 1];
    strcpy_s(value, strlen(temp) + 1, temp);
    delete[] temp;
}

Number::~Number() {
    delete[] value;
}

Number::Number(const Number& other) {//copy constr
    base = other.base;
    value = new char[strlen(other.value) + 1];
    strcpy_s(value, strlen(other.value) + 1, other.value);
}

Number::Number(Number&& other) noexcept {//move constr
    base = other.base;
    value = other.value;
    other.value = nullptr;
}

Number& Number::operator=(const Number& other) {//copy operator
    if (this != &other) {
        delete[] value; // free la memorie obiect
        base = other.base; //transfer baza
        value = new char[strlen(other.value) + 1]; //alocare
        strcpy_s(value, strlen(other.value) + 1, other.value); 
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {//move operator
    if (this != &other) {
        delete[] value;
        base = other.base;
        value = other.value;//take over la memory pointer de la other
        other.value = nullptr;// prevent other from deleting memory later
    }
    return *this;
}

Number& Number::operator=(const char* str) { //release
    delete[] value;
    value = new char[strlen(str) + 1];
    strcpy_s(value, strlen(str) + 1, str);
    return *this;
}

Number& Number::operator=(int num) {
    char* temp = ConvertFromBase10(num, base);
    delete[] value;
    value = new char[strlen(temp) + 1];
    strcpy_s(value, strlen(temp) + 1, temp);
    delete[] temp;
    return *this;
}

Number operator+(const Number& n1, const Number& n2) {
    int num1 = ConvertToBase10(n1.value, n1.base);
    int num2 = ConvertToBase10(n2.value, n2.base);
    int sum = num1 + num2;
    int newBase = max(n1.base, n2.base);
    char* resultStr = ConvertFromBase10(sum, newBase);
    Number result(resultStr, newBase);
    delete[] resultStr;
    return result;
}

Number operator-(const Number& n1, const Number& n2) {
    int num1 = ConvertToBase10(n1.value, n1.base);
    int num2 = ConvertToBase10(n2.value, n2.base);
    int diff = num1 - num2;
    int newBase = max(n1.base, n2.base);
    char* resultStr = ConvertFromBase10(diff, newBase);
    Number result(resultStr, newBase);
    delete[] resultStr;
    return result;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

char Number::operator[](int index) const {
    if (index >= 0 && index < static_cast<int>(strlen(value))) {
        return value[index];
    }
    return '\0';
}

bool Number::operator>(const Number& other) const {
    return ConvertToBase10(value, base) > ConvertToBase10(other.value, other.base);
}

bool Number::operator<(const Number& other) const {
    return ConvertToBase10(value, base) < ConvertToBase10(other.value, other.base);
}

bool Number::operator>=(const Number& other) const {
    return ConvertToBase10(value, base) >= ConvertToBase10(other.value, other.base);
}

bool Number::operator<=(const Number& other) const {
    return ConvertToBase10(value, base) <= ConvertToBase10(other.value, other.base);
}

bool Number::operator==(const Number& other) const {
    return ConvertToBase10(value, base) == ConvertToBase10(other.value, other.base);
}

Number& Number::operator--() {
    if (strlen(value) > 1) {
        memmove(value, value + 1, strlen(value));
        //value[strlen(value) - 1] = '\0';
    }
    else {
        value[0] = '0';
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    if (strlen(value) > 1) {
        value[strlen(value) - 1] = '\0';
    }
    else {
        value[0] = '0';
    }
    return temp;
}

void Number::SwitchBase(int newBase) {
    int num = ConvertToBase10(value, base);
    char* newVal = ConvertFromBase10(num, newBase);
    delete[] value;
    value = new char[strlen(newVal) + 1];
    strcpy_s(value, strlen(newVal) + 1, newVal);
    delete[] newVal;
    base = newBase;
}

void Number::Print() const {
    cout << value << " (base " << base << ")" << endl;
}

int Number::GetDigitsCount() const {
    return static_cast<int>(strlen(value));
}

int Number::GetBase() const {
    return base;
}