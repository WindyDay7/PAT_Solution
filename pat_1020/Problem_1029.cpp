#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int find_k(vector<int> &num1, vector<int> &num2, int k, int start1, int start2)
{
    int min_num = 0, temp_k = 0;
    int next1 = 0, next2 = 0;
    int number1 = 0, number2 = 0, step1 = 0, step2 = 0;
    if(start1 == num1.size()) {
        return num2[start2 + k - 1];
    }
    if(start2 == num2.size()) {
        return num1[start1 + k - 1];
    }

    if(k == 1) {
        min_num = min(num1[start1], num2[start2]);
        return min_num;
    }
    temp_k = k/2;
    if(start1 + temp_k > num1.size()) {
        next1 = num1.size() - 1;
        step1 = k - next1 + start1 - 1;
    }
    else {
        next1 = start1 + temp_k - 1;
        step1 = k - temp_k;
    }
    if(start2 + temp_k > num2.size()) {
        next2 = num2.size() - 1;
        step2 = k - next2 + start2 - 1;
    }
    else {
        next2 = start2 + temp_k - 1;
        step2 = k - temp_k;
    }
    number1 = num1[next1];
    number2 = num2[next2];
    if(number1 > number2) {
        return find_k(num1, num2, step2, start1, next2+1);
    }
    else {
        return find_k(num1, num2, step1, next1+1, start2);
    }
    return 0;
}


int main() 
{
    int N1 = 0, N2 = 0;
    cin >> N1;
    int temp = 0, mid = 0;
    int result = 0, result1 = 0;
    vector<int> num1;
    vector<int> num2;
    for (int i = 0; i < N1; i++)
    {
        cin >> temp; 
        num1.push_back(temp);
    }
    cin >> N2;
    for (int i = 0; i < N2; i++)
    {
        cin >> temp;
        num2.push_back(temp);
    }
    mid = (N1+N2+1) / 2;
    result = find_k(num1, num2, mid, 0, 0);
    cout << result << endl;
    return 0;
}