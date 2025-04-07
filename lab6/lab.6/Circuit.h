#pragma once

#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

class Circuit {
private:
    int raceWeather;
    double trackLength;

    int numCars;
    Car* carArray[10];

    bool didFinish[10];
    double finishTimes[10];
    int numFinished;

    void Swap(int i, int j);
    void SortRaceTimes();
public:
    Circuit();
    void SetLength(double length);
    void SetWeather(int weather);
    void AddCar(Car* newCar);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};
