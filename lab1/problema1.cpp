#include <stdio.h>
#include <cstring>
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
    char b[101];
    float totalSum = 0.0f;
    FILE* file;

    file = fopen("in.txt", "r");
    while (fgets(b, 101, file) != NULL) {
        totalSum += convert2float(b);
        strcpy(b, "");
    }
    fclose(file);
    printf("Sum is: %0.0f", totalSum);
}
