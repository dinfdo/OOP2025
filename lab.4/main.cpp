#include <iostream>
#include "Sort.h"
using namespace std;

int main() {
    Sort s1(5, 1, 50);
    s1.Print();

    vector<int> vec = { 15, 9, 20, 11, 4 };
    Sort s3(vec, vec.size());
    s3.Print();

    Sort s4(6, 12, 33, 5, 18, 9, 22);
    s4.Print();

    Sort s5("10,40,100,5,70");
    s5.Print();

    s1.InsertSort(true);
    s1.Print();

    s3.QuickSort(true);
    s3.Print();

    s4.BubbleSort(true);
    s4.Print();

    return 0;
}
