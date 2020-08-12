#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    char number[21] = {0}, result[21] = {0};
    int a[10] = {0}, b[10] = {0};
    scanf("%s", number);
    int carry = 0, temp = 0;
    for (int i = strlen(number) -1; i>=0; i--)
    {
        temp = (number[i] - '0') * 2;
        a[number[i] - '0'] += 1;
        number[i] = (temp)%10  + carry + '0';
        carry = temp >= 10? 1:0;
        if(i == 0 && carry == 1) {
            cout << "No" << endl;
            cout << "1" << number << endl;
            return 0;
        }
    }
    for (int i = 0; i<strlen(number); i++)
    {
        b[number[i] - '0'] += 1;
    }
    for (int i = 0; i < 10; i++)
    {
        if(a[i] != b[i]) {
            cout << "No" << endl << number << endl;
            return 0;
        }
    }
    cout << "Yes" << endl << number << endl;
    return 0;
}