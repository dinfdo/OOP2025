#pragma once

class Student
{
    float MathGrade, HistoryGrade, EnglishGrade;
    char* name;
public:
    void SetName(const char* newName, int s);
    const char* GetName();

    void SetMathGrade(float grade);
    float GetMathGrade();

    void SetEnglishGrade(float grade);
    float GetEnglishGrade();

    void SetHistoryGrade(float grade);
    float GetHistoryGrade();

    float GetAverage();  
};
