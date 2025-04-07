#pragma once

#include "Car.h"

class RangeRover : public Car {
public:
    RangeRover();
    const char* GetName() override;
    double CalculateTime(int weatherCode, double trackLength, bool& finished) override;
};