#include "Fiat.h"
#include "Weather.h"

Fiat::Fiat() {
    this->fuelCap = 39;          
    this->fuelCons = 1.5;         

    this->avgSpeed[0] = 45;      // Rain
    this->avgSpeed[1] = 100;     // Sunny
    this->avgSpeed[2] = 30;      // Snow

    this->carName = "Fiat";
}

const char* Fiat::GetName() {
    return this->carName;
}

double Fiat::CalculateTime(int weatherCode, double trackLength, bool& finished) {
    int speed = this->avgSpeed[weatherCode];

    double availableTime = this->fuelCap / this->fuelCons;
    double possibleDistance = availableTime * speed;

    if (possibleDistance >= trackLength)
        finished = true;
    else
        finished = false;

    double finishTime = trackLength / speed;
    return finishTime;
}
