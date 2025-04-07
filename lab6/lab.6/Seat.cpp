#include "Seat.h"
#include "Weather.h"

Seat::Seat() {
    this->fuelCap = 39;          
    this->fuelCons = 1.5;         

    this->avgSpeed[0] = 50;      // Rain
    this->avgSpeed[1] = 110;     // Sunny
    this->avgSpeed[2] = 38;      // Snow

    this->carName = "Seat";
}

const char* Seat::GetName() {
    return this->carName;
}

double Seat::CalculateTime(int weatherCode, double trackLength, bool& finished) {
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
