#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int test = 0;
    cin >> test;
    string str_in;
    int length = 0;
    vector<int> stack1, stack2;
    int new_position = 0;
    while (test--)
    {
        stack1.clear(); stack2.clear();
        cin >> length;
        cin >> str_in;
        vector<int> position(length+5);
        for (int i = 0; i < length; i++)
        {
            new_position = stack1.size() + stack2.size();
            if(str_in[i] == '0') {
                if(stack2.empty()) {
                    stack1.push_back(new_position);
                }
                else {
                    new_position = stack2.back();
                    stack2.pop_back();
                    stack1.push_back(new_position);
                }
            }
            else {
                if(stack1.empty()) {
                    stack2.push_back(new_position);
                }
                else {
                    new_position = stack1.back();
                    stack1.pop_back();
                    stack2.push_back(new_position);
                }
            }
            position[i] = new_position + 1;
        }
        cout << stack1.size() + stack2.size() << endl;
        for (int i = 0; i < length; i++)
        {
            cout << position[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}