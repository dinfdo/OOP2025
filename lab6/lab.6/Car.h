#pragma once

class Car {
protected:
    const char* carName;
    double fuelCap;        // l/h
    double fuelCons;       // l/100Km
    int avgSpeed[3];       // km/h
public:
    virtual const char* GetName() = 0;
    virtual double CalculateTime(int weatherCode, double trackLength, bool& finished) = 0;
};
