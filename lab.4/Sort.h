#ifndef SORT_H
#define SORT_H
#include <initializer_list>
#include <vector>
#include <cstdarg>
#include <string>
using namespace std;
class Sort
{
private:
    int nrElem;
    vector<int> lista;
public:
    // add constuctors
    Sort(int n, int mini, int maxi);
    Sort(initializer_list <int> list);
    Sort(vector<int> v, int n);
    Sort(int count, ...);
    Sort(const char* nr);
    void InsertSort(bool ascendent = false);
    int Partition(int st, int dr, bool ascendent);
    void QuickSortRecursive(int st, int dr, bool ascendent);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
#endif // pt SORT_H

