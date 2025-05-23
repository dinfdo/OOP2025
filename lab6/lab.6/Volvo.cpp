#include "Volvo.h"
#include "Weather.h"

Volvo::Volvo() {
    this->fuelCap = 59;          
    this->fuelCons = 2;         

    this->avgSpeed[0] = 60;      // Rain
    this->avgSpeed[1] = 140;     // Sunny
    this->avgSpeed[2] = 40;      // Snow

    this->carName = "Volvo";
}

const char* Volvo::GetName() {
    return this->carName;
}

double Volvo::CalculateTime(int weatherCode, double trackLength, bool& finished) {
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
