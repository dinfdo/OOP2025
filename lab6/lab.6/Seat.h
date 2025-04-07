#pragma once

#include "Car.h"

class Seat : public Car {
public:
    Seat();
    const char* GetName() override;
    double CalculateTime(int weatherCode, double trackLength, bool& finished) override;
};