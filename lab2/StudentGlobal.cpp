#include "StudentGlobal.h"

int StudentGlobal::CompareName(Student s1, Student s2) {
    if (s1.GetName() == s2.GetName()) {
        return 0;
    }
    else if (s1.GetName() < s2.GetName()) {
        return -1;
    }
    else {
        return 1;
    }
}

int StudentGlobal::CompareMathGrade(Student s1, Student s2) {
    if (s1.GetMathGrade() == s2.GetMathGrade()) {
        return 0;
    }
    else if (s1.GetMathGrade() > s2.GetMathGrade()) {
        return 1;
    }
    else {
        return -1;
    }
}

int StudentGlobal::CompareEnglishGrade(Student s1, Student s2) {
    if (s1.GetEnglishGrade() == s2.GetEnglishGrade()) {
        return 0;
    }
    else if (s1.GetEnglishGrade() > s2.GetEnglishGrade()) {
        return 1;
    }
    else {
        return -1;
    }
}

int StudentGlobal::CompareHistoryGrade(Student s1, Student s2) {
    if (s1.GetHistoryGrade() == s2.GetHistoryGrade()) {
        return 0;
    }
    else if (s1.GetHistoryGrade() > s2.GetHistoryGrade()) {
        return 1;
    }
    else {
        return -1;
    }
}

int StudentGlobal::CompareAverage(Student s1, Student s2) {
    float avg1 = s1.GetAverage();
    float avg2 = s2.GetAverage();

    if (avg1 == avg2) {
        return 0;
    }
    else if (avg1 > avg2) {
        return 1;
    }
    else {
        return -1;
    }
}
