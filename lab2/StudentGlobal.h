#pragma once
#include "Student.h"

class StudentGlobal {
public:
    int CompareName(Student a, Student b);
    int CompareMathGrade(Student a, Student b);
    int CompareEnglishGrade(Student a, Student b);
    int CompareHistoryGrade(Student a, Student b);
    int CompareAverage(Student a, Student b);
};
