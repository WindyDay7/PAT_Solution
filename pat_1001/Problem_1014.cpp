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
    if((hour > 17) || (hour == 17 && minutes != 0)) {
        cout << "sorry";
        return ;
    }
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

Customer Write_info(int number, int need_time)
{
    Customer temp_customer;
    temp_customer.number = number;
    temp_customer.need_time = need_time;
    return temp_customer;
}

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
        time += 1;
        for (int i = 0; i < bank.size(); i++)
        {
            if(bank[i].empty()) {
                continue;
            }
            bank[i].front().need_time -= 1;
            Customer temp_customer = bank[i].front();
            if(temp_customer.need_time == 0) {
                result[temp_customer.number] = time;
                bank[i].pop();
                if(remain < customer_num) {
                    Customer new_customer = Write_info(remain, transaction_time[remain]);
                    remain += 1;
                    bank[i].push(new_customer);
                }
            }
        }
    }
    for (int i = 0; i < query_num; i++)
    {
        output_time(result[query[i] - 1]);
    }
    return 0;
}
