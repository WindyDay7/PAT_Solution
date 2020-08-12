#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node_num
{
    int next;
    char letter;
    bool flag;
};

Node_num node_array[100001];

int main()
{
    int start1 = 0, start2 = 0;
    int N = 0, result = -1;
    cin >> start1 >> start2 >> N;
    Node_num temp_node;
    int count = 0;
    int temp_num1 = 0, temp_num2 = 0;
    char temp_char = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp_num1 >> temp_char >> temp_num2;
        node_array[temp_num1].letter = temp_char;
        node_array[temp_num1].next = temp_num2;
        node_array[temp_num1].flag = false;
    }
    for (int i = start1; i != -1; i = node_array[i].next)
    {
        node_array[i].flag = true;
    }
    for (int i = start2; i != -1; i = node_array[i].next)
    {
        if(node_array[i].flag == true) {
            result = i;
            break;
        }
    }
    if(result == -1) {
        cout << -1 << endl;
        return 0;
    }
    printf("%05d\n", result);
    return 0;
}