#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int number;
    Node* next;
};


int main()
{
    int total = 0, noleaf_num = 0, digit = 0, child_num = 0;
    int i = 0, j = 0, temp = 0;
    int result[100][100] = {0};
    int child_count[100] = {0}, color[100] = {0}, result_num[100] = {0};
    int next_layer = 0, this_layer = 0, temp_layer = 0, k = 0, temp_result_num = 0;

    queue<int> temp_queue;
    cin >> total; cin >> noleaf_num;
    for (i = 0; i < noleaf_num; i++) {
        cin >> digit; cin >> child_num; 
        child_count[digit] = child_num;
        for(j = 0; j<child_num; j++) {
            cin >> temp;
            result[digit][temp] = 1;
        }
    }
    temp_queue.push(1);
    color[1] = 1;
    this_layer = 1;
    while (!temp_queue.empty())
    {
        temp = temp_queue.front();
        temp_queue.pop();
        for (i = 1; i < 100; i++)
        {
            if(color[i] == 0) {
                if(result[temp][i]) {
                    temp_queue.push(i);
                    if(child_count[i] == 0) {
                        temp_result_num += 1;
                    }
                    next_layer += 1;
                    color[i] = 1;
                }
            }
        }
        temp_layer += 1;
        if(temp_layer == this_layer) {
            this_layer = next_layer;
            result_num[k++] = temp_result_num;
            // cout << result_num << " ";
            temp_layer = 0; next_layer = 0;
            temp_result_num = 0; 
        }
        color[temp] = 2;
    }
    if(child_count[1] == 0) {
        cout << 1;
        return 0;
    }
    cout << 0;
    for(i = 0; i<k-1; i++) {
        cout << " " << result_num[i];
    }
    return 0;
}