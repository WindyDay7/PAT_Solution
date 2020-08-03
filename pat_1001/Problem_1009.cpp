#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

#define DOUBLE_EPS 1e-15

int main()
{
    int K1 = 0, K2 = 0, count = 0;
    int temp_exponent = 0, exponent1 = 0, exponent2 = 0;
    double temp_coefficient = 0;
    double polynomial1[1001] = {0}, polynomial2[1001] = {0}, result[2003] = {0}; 
    cin >> K1;
    for (int i = 0; i < K1; i++) {
        cin >> temp_exponent >> temp_coefficient;
        polynomial1[temp_exponent] = temp_coefficient;
    }
    cin >> K2;
    for (int i = 0; i < K2; i++) {
        cin >> temp_exponent >> temp_coefficient;
        polynomial2[temp_exponent] = temp_coefficient;
    }
    for (int i = 0; i < 1001; i++)
    {
        if(fabs(polynomial1[i]) <= DOUBLE_EPS) {
            continue;
        }
        exponent1 = i;
        for (int j = 0; j < 1001; j++)
        {
            if(fabs(polynomial2[j]) <= DOUBLE_EPS) {
                continue;
            }
            exponent2 = j;
            result[i+j] = polynomial1[i] * polynomial2[j] + result[i+j];
        }
    }
    for (int i = 0; i < 2002; i++)
    {
        if(result[i] != 0) {
            count += 1;
        }
    }
    cout << count;
    for (int i = 2001; i >= 0; i--)
    {
        if(result[i] != 0) {
            printf(" %d %.1f",i, result[i]);
        }
    }
    return 0;
}