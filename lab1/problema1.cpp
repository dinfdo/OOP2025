#include <stdio.h>
#include <cstring>
<<<<<<< HEAD
using namespace std;

float convert2float(char v[]) {
    float val = 0.0f;
    float decimfac = 1.0f;
    bool Negativ = false;
    bool hasdecim = false;
    int i = 0;

    if (v[i] == '-') {
        Negativ = true;
        i++;
    }

    for (i = 0; i < strlen(v); i++) {
        if (v[i] == '.') {
            if (hasdecim) {
                return 0.0f;
            }
            hasdecim = true;
        } else if (v[i] >= '0' && v[i] <= '9') {
            if (hasdecim) {
                decimfac /= 10.0f;
                val += (v[i] - '0') * decimfac;
            } else {
                val = val * 10.0f + (v[i] - '0');
            }
        }
    }
    if (Negativ) {
        val = -val;
    }
    return val;
}

int main() {
    char buffer[101];
    float totalSum = 0.0f;
    FILE* file;

    file = fopen("in.txt", "r");
    while (fgets(buffer, 101, file) != NULL) {
        totalSum += convert2float(buffer);
        strcpy(buffer, "");
    }
    fclose(file);
    printf("Sum is: %0.0f", totalSum);
=======

using namespace std;

float chartofloat(char str[])
{
    float rezultat = 0.0f;
    float fractie = 1.0f;
    bool esteNegativ = false;
    bool esteFractie = false;
    int i = 0;

    if (str[i] == '-')
    {
        esteNegativ = true;
        i++;
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            if (esteFractie)
            {
                return 0.0f;
            }
            esteFractie = true;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            if (esteFractie)
            {
                fractie /= 10.0f;
                rezultat += (str[i] - '0') * fractie;
            }
            else
            {
                rezultat = rezultat * 10.0f + (str[i] - '0');
            }
        }
    }
    if (esteNegativ)
    {
        rezultat = -rezultat;
    }

    return rezultat;
}

int main()
{
    char str[101];
    float sum = 0.0f;
    FILE* openFile;

    openFile = fopen("in.txt", "r");

    while (fgets(str, 101, openFile) != NULL)
    {
        sum += chartofloat(str);
        strcpy(str, "");
    }

    fclose(openFile);
    printf("Sum is: %0.0f", sum);
>>>>>>> 42a04aad8e8b02246a02c00bbfcd8cffb3ba4401
    return 0;
}
