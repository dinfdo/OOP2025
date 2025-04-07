#pragma once

#include "Car.h"

class BMW : public Car {
public:
    BMW();
    const char* GetName() override;
    double CalculateTime(int weatherCode, double trackLength, bool& finished) override;
};