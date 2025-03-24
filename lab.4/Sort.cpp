#include "Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

Sort::Sort(int n, int mini, int maxi)
{
    nrElem = n;
    lista.clear();  
    int range = maxi - mini;
    for (int i = 0; i < nrElem; i++)
    {
        lista.push_back(mini + (rand() % range));  
    }
}

Sort::Sort(initializer_list<int> list)
{
    nrElem = list.size();
    lista.clear();  
    for (int num : list)
    {
        lista.push_back(num); 
    }
}

Sort::Sort(vector<int> v, int n)
{
    nrElem = n;
    lista = v;  
}

Sort::Sort(int count, ...)
{
    va_list args;
    va_start(args, count);

    nrElem = count;
    lista.clear();  
    for (int i = 0; i < nrElem; i++)
    {
        lista.push_back(va_arg(args, int));  
    }
    va_end(args);
}

Sort::Sort(const char* str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ',')
            count++;  

    lista.reserve(count + 1);  

    int value = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ',')  
        {
            lista.push_back(value);
            value = 0;
        }
        else 
        {
            value = value * 10 + (str[i] - '0');
        }
    }
    lista.push_back(value);  

    nrElem = lista.size(); 
}

void Sort::InsertSort(bool ascendent)
{
    int temp;
    for (int i = 1; i < nrElem; i++)
    {
        temp = lista[i];
        int j = i - 1;

        while (j >= 0 && lista[j] > temp)
        {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = temp;
    }
}

int Sort::Partition(int st, int dr, bool ascendent)
{
    int pivot = lista[dr];
    int i = st - 1;

    for (int j = st; j < dr; j++)
    {
        if ((ascendent && lista[j] < pivot) || (!ascendent && lista[j] > pivot))
        {
            i++;
            swap(lista[i], lista[j]);
        }
    }
    swap(lista[i + 1], lista[dr]);
    return i + 1;
}

void Sort::QuickSortRecursive(int st, int dr, bool ascendent)
{
    if (st < dr)
    {
        int pivot = Partition(st, dr, ascendent);
        QuickSortRecursive(st, pivot - 1, ascendent); 
        QuickSortRecursive(pivot + 1, dr, ascendent);  
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortRecursive(0, nrElem - 1, ascendent);  
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < nrElem - 1; i++)
    {
        for (int j = 0; j < nrElem - i - 1; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                int aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

void Sort::Print()
{
    for (int i = 0; i < nrElem; i++)
    {
        printf("%d ", lista[i]); 
    }
    printf("\n");
}

int Sort::GetElementsCount()
{
    return nrElem;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < nrElem)
    {
        return lista[index];
    }
    return -1;
}
