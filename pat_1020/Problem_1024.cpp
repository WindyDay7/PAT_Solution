#include<iostream>
#include<stdio.h>
#include<string>
#include <algorithm>

using namespace std;


bool deter_Palind(string str_p)
{
    int i = 0,j = str_p.length()-1;
    while(i <= j) {
        if(str_p[i] != str_p[j]) {
            return false;
        }
        i++; j--;
    }
    return true;
}

string get_next(string str_in) 
{
    string str2 = str_in;
    string result;
    char temp = 0;
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = str_in.length() - 1; i >= 0; i--)
    {
        temp = (str_in[i]-'0') + (str2[i]-'0') + carry;
        carry = temp > 9?1:0;
        temp = temp%10;
        result.push_back(temp+'0');
    }
    if(carry == 1) {
        result.push_back('1');
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string str_in, temp_str;
    int count = 0;
    cin >> str_in;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        if(deter_Palind(str_in)) {
            cout << str_in << endl << i << endl;
            return 0;
        }
        temp_str = get_next(str_in);
        str_in = temp_str;
    }
    cout << str_in << endl << count << endl;
    return 0;
}