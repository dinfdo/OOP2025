#include "BMW.h"
#include "Weather.h"

BMW::BMW() {
    this->fuelCap = 1;          
    this->fuelCons = 3;          

    this->avgSpeed[0] = 55;      // Rain
    this->avgSpeed[1] = 135;     // Sunny
    this->avgSpeed[2] = 40;      // Snow

    this->carName = "BMW";
}

const char* BMW::GetName() {
    return this->carName;
}

double BMW::CalculateTime(int weatherCode, double trackLength, bool& finished) {
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
