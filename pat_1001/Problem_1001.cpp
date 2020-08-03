#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main() 
{
    double a[1001] = {0}, b[1001] = {0}, result[1001] = {0};
    int temp = 0, number = 0;
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> temp;
        cin >> a[temp];
    }
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> temp;
        cin >> b[temp];
    }
    number = 0;
    for (int i = 0; i <= 1000; i++)
    {
        result[i] = a[i] + b[i];
        if(result[i] != 0) {
            number ++;
        }
    }
    cout << number;
    for (int i = 1000; i >= 0; i--)
    {
        if(result[i] != 0.0) {
            cout << " " << i;
            printf(" %.1f", result[i]);
        }
    }
    
}