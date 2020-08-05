#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct Customer
{
    int number;
    int need_time;
};


void output_time(int minutes)
{
    int hour = minutes / 60 + 8;
    minutes = minutes % 60;
    if(hour < 10) {
        cout << "0" << hour << ":";
    }
    else {
        cout << hour << ":";
    }
    if(minutes < 10) {
        cout << "0" << minutes;
    }
    else {
        cout << minutes;
    }
    cout << endl;
    return ;
}

// write information of the customer
Customer Write_info(int number, int need_time)
{
    Customer temp_customer;
    temp_customer.number = number;
    temp_customer.need_time = need_time;
    return temp_customer;
}

// determine whether all the windows are free, this means no customers 
bool end_flag(vector<queue<Customer> > &bank)
{
    for (int i = 0; i < bank.size(); i++)
    {
        if(!bank[i].empty()) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<queue<Customer> > bank;
    int win_num = 0, max_capacity = 0, customer_num = 0, query_num = 0;
    cin >> win_num >> max_capacity >> customer_num >> query_num;
    vector<int> transaction_time, query, result;
    for (int i = 0; i < customer_num; i++)
    {
        transaction_time.push_back(0);
        result.push_back(0);
    }
    for (int i = 0; i < query_num; i++)
    {
        query.push_back(0);
    }

    int time = 0, remain = 0;
    for (int i = 0; i < customer_num; i++)
    {
        cin >> transaction_time[i];
    }
    for (int i = 0; i < query_num; i++)
    {
        cin >> query[i];
    }
    for (int i = 0; i < win_num; i++)
    {
        queue<Customer> new_qeue;
        bank.push_back(new_qeue);
    }
    // cout << bank.size() << endl;
    // the first No. win_num people are sreved at 8:00

    for (int j = 0; j < max_capacity; j++)
    {
        for (int i = 0; i < win_num; i++)
        {
            if(remain < customer_num) {
                Customer temp_customer = Write_info(remain, transaction_time[remain]);
                remain += 1;
                bank[i].push(temp_customer);
            }
            else {
                break;
            }
        }
    }
    while (end_flag(bank))
    {
        // with the time add automatically
        time += 1;
        // traverse all the serve windows
        for (int i = 0; i < bank.size(); i++)
        {
            // if this windows is empty, then, it will no customer add it's queue
            if(bank[i].empty()) {
                continue;
            }
            // the servering customer's need time decrease 1
            bank[i].front().need_time -= 1;
            // get the servering customer in the windows queue
            Customer temp_customer = bank[i].front();
            // if this Customer's need time == 0, it have been srevered, so pop it from the queue
            if(temp_customer.need_time == 0) {
                // the server's end time of customer number is time
                result[temp_customer.number] = time;
                // this customer was pop 
                bank[i].pop();
                // if there are remain some customers wait to server
                if(remain < customer_num) {
                    // add new servered customer to the queue
                    Customer new_customer = Write_info(remain, transaction_time[remain]);
                    remain += 1;
                    bank[i].push(new_customer);
                }
            }
        }
    }    
    for (int i = 0; i < query_num; i++)
    {
        int temp = result[query[i] - 1] - transaction_time[query[i] - 1];
        if(temp >= 540) {
            cout << "Sorry" << endl;
            continue;
        }
        output_time(result[query[i] - 1]);
    }
    return 0;
}
