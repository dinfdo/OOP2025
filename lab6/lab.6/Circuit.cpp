#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
using namespace std;

Circuit::Circuit() : raceWeather(0), trackLength(0), numCars(0), numFinished(0) {
    for (int i = 0; i < 10; i++) {
        carArray[i] = nullptr;
        didFinish[i] = false;
        finishTimes[i] = 0.0;
    }
}

void Circuit::SetLength(double length) {
    trackLength = length;
}

void Circuit::SetWeather(int weather) {
    raceWeather = weather;
}

void Circuit::AddCar(Car* newCar) {
    if (numCars < 10) {
        carArray[numCars] = newCar;
        numCars++;
    }
}

void Circuit::Swap(int i, int j) {
    Car* tempCar = carArray[i];
    carArray[i] = carArray[j];
    carArray[j] = tempCar;

    double tempTime = finishTimes[i];
    finishTimes[i] = finishTimes[j];
    finishTimes[j] = tempTime;

    bool tempFinished = didFinish[i];
    didFinish[i] = didFinish[j];
    didFinish[j] = tempFinished;
}

void Circuit::SortRaceTimes() {
    for (int i = 0; i < numCars - 1; i++) {
        for (int j = 0; j < numCars - i - 1; j++) {
            if (didFinish[j] && didFinish[j + 1] && finishTimes[j] > finishTimes[j + 1]) {
                Swap(j, j + 1);
            }
        }
    }
}

void Circuit::Race() {
    numFinished = 0; 
    for (int i = 0; i < numCars; i++) {
        bool finished;
        finishTimes[i] = carArray[i]->CalculateTime(raceWeather, trackLength, finished);
        didFinish[i] = finished;
        if (finished)
            numFinished++;
    }
    SortRaceTimes();
}

void Circuit::ShowFinalRanks() const {
    cout << "Final rankings are: " << endl;
    int rank = 1;
    for (int i = 0; i < numCars; i++) {
        if (didFinish[i]) {
            cout << rank << ". " << carArray[i]->GetName() << " (Time: " << finishTimes[i] << ")" << endl;
            rank++;
        }
    }
    cout << endl;
}

void Circuit::ShowWhoDidNotFinish() const {
    cout << "The cars which did not finish the race are: " << endl;
    for (int i = 0; i < numCars; i++) {
        if (!didFinish[i])
            cout << carArray[i]->GetName() << endl;
    }
}
