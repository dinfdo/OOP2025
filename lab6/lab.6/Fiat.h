#pragma once

#include "Car.h"

class Fiat : public Car {
public:
    Fiat();
    const char* GetName() override;
    double CalculateTime(int weatherCode, double trackLength, bool& finished) override;
};