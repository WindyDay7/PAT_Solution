#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;


int get_coefficient(char temp)
{
    int result = 0;
    result = temp - '0';
    if(temp > '9') {
        result = temp - 'a' + 10;
    }
    return result;
}

long long get_num(int radix, char *array)
{
    long long result = 0;
    int i = 0, exponent = 0, temp_radix = 0;
    i = strlen(array) - 1;
    while (i >= 0)
    {
        temp_radix = get_coefficient(array[i]);
        result = result + temp_radix * (long long)(pow(radix, exponent));
        if(result < 0) {
            return -1;
        }
        exponent += 1;
        i--;
    }
    return result;
}

long long determine(char *N1, int radix, char *N2)
{
    long long low = 0, mid = 0, high = 0, result = 0;
    long long number1 = 0, number2 = 0;
    int i = 0, min = 0;

    for (i = 0; N2[i]!=0; i++)
    {
        if(get_coefficient(N2[i]) >= min) {
            min = get_coefficient(N2[i]);
        }
    }
    number1 = get_num(radix, N1);
    low = min+1; 
    
    high = number1 > low? number1:low; 
    while(low <= high) {
        mid = (low+high) / 2;
        number2 = get_num(mid, N2);
        if(number2 < 0 || number2 > number1) {
            high = mid - 1;
        }
        else if(number2 < number1) {
            low = mid+1;
        }
        else {
            result = mid;
            break;
        }
    }
    if(result == 0) {
        return -1;
    }
    for (i = 0; N2[i]!=0; i++) {
        if(get_coefficient(N2[i]) >= result) {
            return -1;
        }
    }
    return result;
}

int main()
{
    char N1[11] = {0}, N2[11] = {0};
    long long result = 0;
    scanf("%s", N1); scanf("%s", N2); 
    int tag = 0, radix = 0;
    cin >> tag; cin >> radix;
    if(tag == 1) {
        result = determine(N1, radix, N2);
    }
    else {
        result = determine(N2, radix, N1);
    }
    if(result > 0) {
        cout << result;
        return 0;
    }
    cout << "Impossible";
    return 0;
}