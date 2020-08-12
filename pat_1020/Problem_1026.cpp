#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


struct Customer
{
    int arrive_time, play_time, VIP_flag, serve_time;
};

struct Table
{
    Customer playing_customer;
    int number, vip_flag;
};
Table init_table;


int time_to_minutes(char* time)
{
    char temp[3] = {0};
    strncpy(temp, time, 3);
    temp[2] = 0;
    int hour = 0, minute = 0, second = 0, result = 0;
    hour = atoi(temp);
    strncpy(temp, time+3, 3);
    temp[2] = 0;
    minute = atoi(temp);
    strncpy(temp, time + 6, 3);
    temp[2] = 0;
    second = atoi(temp);
    result = 360*(hour-8)+minute*60+second;
    return result;
}

bool cmp(Customer a, Customer b)
{
    if(a.arrive_time < b.arrive_time) {
        return true;
    }
    return false;
}

bool cmp2(Table a, Table b)
{
    if(a.vip_flag > b.vip_flag) {
        return true;
    }
    return false;
}

bool end_flag(vector<Customer> &temp_array, queue<Customer> &general, queue<Customer> &VIP, vector<Table> &table)
{
    if(temp_array.empty() && general.empty() && VIP.empty() && table.empty()) {
        return false;
    }
    return true;
}

int main()
{
    int N = 0;
    Customer temp_customer;
    char temp_arrive[10] = {0};
    vector<Customer> temp_array;
    queue<Customer> general;
    queue<Customer> VIP; 
    vector<Table> table;
    vector<Customer> result;
    queue<int> temp_VIP_table, temp_g_table;
    int table_num = 0, vip_table_num = 0, temp_vip_flag = 0;
    int play_time = 0, vip_flag = 0;
    int time_count = 0;
    int general_num = 0, VIP_num = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", temp_arrive); 
        // play_time is how long players play 
        cin >> play_time >> vip_flag;
        temp_customer.arrive_time = time_to_minutes(temp_arrive);
        temp_customer.play_time = play_time;
        temp_customer.VIP_flag = vip_flag;
        temp_array.push_back(temp_customer);
    }
    sort(temp_array.begin(), temp_array.end(), cmp);
    cin >> table_num >> vip_table_num;
    for (int i = 0; i < table_num; i++)
    {
        table.push_back(init_table);
    }
    for (int i = 0; i < vip_table_num; i++)
    {
        cin >> temp_vip_flag;
        table[temp_vip_flag-1].vip_flag = 1;
    }
    sort(table.begin(), table.end(), cmp2);
    while (end_flag(temp_array, general, VIP, table))
    {
        temp_customer = temp_array.front();
        if(time_count == temp_customer.arrive_time) {
            temp_array.erase(temp_array.begin());
            if(temp_customer.VIP_flag == 1) {
                VIP.push(temp_customer);
            }
            else {
                general.push(temp_customer);
            }
        }
        // 统计已经占用的桌子的个数
        for (int i = 0; i < table.size(); i++)
        {
            if(table[i].playing_customer.play_time != 0) {
                table[i].playing_customer.play_time -= 1;
            }
            if(table[i].playing_customer.play_time != 0) {
                if(table[i].vip_flag == 1) {
                    temp_VIP_table.push(i);
                }
                else {
                    temp_g_table.push(i);
                }
            }
            if(table[i].playing_customer.play_time == 0) {
                result.push_back(table[i].playing_customer);
        } 
        // if VIP 队列不是空的, 
        if(!VIP.empty()) {
            // If there are free VIP table, VIP table allocated to VIP customer
            if(!temp_VIP_table.empty()) {
                
            }
            // There are no free VIP table, VIP wait as general player
            else {

            }
        }
        // if has general players are waiting
        else if(!general.empty()) {

        }
        else {
            
        }
 

        if((!general.empty() && !VIP.empty() && general.front().arrive_time < VIP.front().arrive_time) || (!general.empty() && VIP.empty())) {
            // the front in general arrive before VIP front 
            if((time_count - general.front().arrive_time) %60 == 0) {
                table[i].playing_customer = general.front();
                table[i].playing_customer.serve_time = time_count;
                general.pop();
            }
        }
        else if((!general.empty() && !VIP.empty() && general.front().arrive_time > VIP.front().arrive_time) || (general.empty() && !VIP.empty())) {
            if((time_count - VIP.front().arrive_time)%60 == 0) {
                table[i].playing_customer = VIP.front();
                table[i].playing_customer.serve_time = time_count;
                VIP.pop();
            } 
        }

        for (int i = 0; i<table.size(); i++)
        {
            
                // this table is general table
                if(table[i].vip_flag == 0) {
                    // chose the first in general and VIP queue, distribute it to this table
                    
                }
                // There is problem here, if VIP and general table both free, what I chose 
                // this table is for VIP
                else {
                    // if VIP queue is empty 
                    if(!VIP.empty() && (time_count - VIP.front().arrive_time)%60 == 0) {
                        table[i].playing_customer = VIP.front();
                        table[i].playing_customer.serve_time = time_count;
                        VIP.pop();
                    }
                    // if VIP queue is emoty 
                    else if(!general.empty() && (time_count - general.front().arrive_time)%60 == 0) {
                        // 如果普通桌子已经满了的话, 一般用户就会使用VIP桌子
                        if(table_num - general_num - vip_table_num <= ) {
                            table[i].playing_customer = general.front();
                            table[i].playing_customer.serve_time = time_count;
                            general.pop();
                        }
                    }
                }
            }
        }
        time_count ++;
    }
    sort(result.begin(), result.end(), cmp);
    return 0;
}