#pragma once

#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    const char* GetName() override;
    double CalculateTime(int weatherCode, double trackLength, bool& finished) override;
};