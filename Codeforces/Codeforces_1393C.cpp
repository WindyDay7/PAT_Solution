#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

map<int,int> cake;

int main()
{
    int Test = 0, result = 0;
    cin >> Test;
    int length = 0, temp = 0, max_num = 0, count = 0;
    while (Test--)
    {
        cake.clear();
        max_num = 0;
        cin >> length;
        for (int i = 0; i < length; i++)
        {
            cin >> temp;
            cake[temp] += 1;
            if(cake[temp] > max_num) {
                max_num = cake[temp];
                count = 1;
            }
            else if(cake[temp] == max_num)
            {
                count += 1;
            }
        }
        result = (length - max_num*count)/(max_num - 1) + count - 1;
        cout << result << endl;
    }
    
    return 0;
}