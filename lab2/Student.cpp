#include "Student.h"
#include <stdio.h>
#include <vcruntime_string.h>
using namespace std;

void Student::SetName(const char* name, int Size)
{
    this->name = new char[Size + 1];
    memcpy(this->name, name, Size);
    this->name[Size] = '\0';
}

const char* Student::GetName() {
    return this->name;
}

void Student::SetMathGrade(float MathGrade) {
    if (MathGrade >= 1 && MathGrade <= 10) {
        this->MathGrade = MathGrade;
    }
}

float Student::GetMathGrade() {
    return this->MathGrade;
}

void Student::SetEnglishGrade(float EnglishGrade) {
    if (EnglishGrade >= 1 && EnglishGrade <= 10) {
        this->EnglishGrade = EnglishGrade;
    }
}

float Student::GetEnglishGrade() {
    return this->EnglishGrade;
}

void Student::SetHistoryGrade(float HistoryGrade) {
    if (HistoryGrade >= 1 && HistoryGrade <= 10) {
        this->HistoryGrade = HistoryGrade;
    }
}

float Student::GetHistoryGrade() {
    return this->HistoryGrade;
}

float Student::GetAverage() {
    return (this->MathGrade + this->EnglishGrade + this->HistoryGrade) / 3.0f;
}
