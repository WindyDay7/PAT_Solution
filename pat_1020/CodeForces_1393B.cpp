#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <map>
using namespace std;

int planks_array[100005];
map<int, int> planks;
int B_2 = 0, B_4 = 0, B_6 = 0, B_8 = 0;

bool deter_op()
{
    int count = 0, flag = 0;
    for(map<int,int>::iterator iter = planks.begin(); iter!=planks.end(); iter++)
    {
        if(iter->second >= 4) {
            flag = 1;
        }
        count += (iter->second / 2);
    }
    if(count >= 4 && flag == 1) {
        return true;
    }
    return false;
}

bool deter(int B_2, int B_4, int B_6, int B_8) 
{
    if(B_8 > 0 || (B_6 > 0 && (B_2 > 0 || B_4 > 0)) || (B_4 > 1) || (B_6 > 1) || (B_4 > 0 && (B_2 > 1))) {
        return true;
    }
    return false;
}

void change_to(int number, int add_flag) 
{
    if(number < 2 && add_flag == 0) {
        B_2 -= 1;
    }
    if(number == 2 || number == 3) {
        B_2 += 1;
        if(add_flag == 0 && number == 3) {
            B_4 -= 1;
        }
    }
    if(number == 5 || number == 4) {
        B_4 += 1;
        if(add_flag == 1 && number == 4) {
            B_2 -= 1;
        }
        if(number == 5 && add_flag == 0) {
            B_6 -= 1;
        }
    }
    if(number == 6 || number == 7) {
        B_6 += 1;
        if(add_flag == 1 && number == 6) {
            B_4 -= 1;
        }
        if(number == 7 && add_flag == 0) {
            B_8 -= 1;
        }
    }
    if(number >= 8) {
        B_8 += 1;
        if(number == 8 && add_flag == 1) {
            B_6 -= 1;
        }
    }
}

int main()
{
    int N = 0;
    cin >> N;
    int temp = 0;
    int op_num = 0;
    char str_temp[15] = {0};
    int temp_count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        planks_array[temp]+= 1;
        temp_count = planks_array[temp];
        if(temp_count%2 == 0) {
            change_to(temp_count, 1);
        }
    }
    cin >> op_num;
    cin.getline(str_temp, 15);
    for (int i = 0; i < op_num; i++)
    {
        cin.getline(str_temp, 15);
        temp = stoi(str_temp+2);
        if(str_temp[0] == '+') {
            planks_array[temp] += 1;
            temp_count = planks_array[temp];
            if(temp_count%2 == 0) {
                change_to(temp_count, 1);
            }
        }
        else {
            planks_array[temp] -= 1;
            temp_count = planks_array[temp];
            if(temp_count%2 == 1) {
                change_to(temp_count, 0);
            }
        }
        
        if(deter(B_2, B_4, B_6, B_8)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}