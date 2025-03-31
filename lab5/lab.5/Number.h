#pragma once
#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
using namespace std;

class Number {
private:
    char* value;
    int base;

public:
    Number(const char* val, int b);
    Number(int num, int b = 10);
    ~Number();

    //copy & move constructori
    Number(const Number& other);
    Number(Number&& other) noexcept;

    //copy & move assignment operatori
    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(const char* str);
    Number& operator=(int num);

    //operatori
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& other);
    char operator[](int index) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    Number& operator--();   // prefix decrement
    Number operator--(int); // postfix decrement

    // metode
    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};

#endif // NUMBER_H
