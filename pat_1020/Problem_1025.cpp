#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Testee
{
    string registration_number;
    int final_rank, location_number, local_rank, score;
};

Testee local_test[305];
Testee final_test[30500];

int Local_Rank(const void *a, const void *b)
{
    Testee *c = (Testee *)a;
    Testee *d = (Testee *)b;
    if(c->score != d->score) {
        return d->score - c->score;
    }
    else {
        return c->registration_number > d->registration_number ?1:-1;
    }
}

bool cmp(Testee a, Testee b)
{
    if(a.score != b.score) {
        return a.score > b.score;
    }
    else {
        return a.registration_number < b.registration_number;
    }
}


int main()
{
    int N; cin >> N;
    int K; 
    string temp_name;
    int temp_score = 0, temp_local_rank = 0, temp_final_rank = 0;
    Testee temp_test;
    int least_num = 0, number = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> temp_name;  cin >> temp_score;

            local_test[j].registration_number = temp_name;
            local_test[j].score = temp_score;
            local_test[j].location_number = i+1;
        }
        sort(local_test, local_test+K, cmp);
        // qsort(local_test, K, sizeof(local_test[0]), Local_Rank);
        for (int j = 0; j < K; j++)
        {
            if(j != 0 && local_test[j].score == local_test[j-1].score) {
                local_test[j].local_rank = local_test[j-1].local_rank;
            }
            else {
                local_test[j].local_rank = j+1;
            }
            final_test[number] = local_test[j];
            number ++;
        }
    }
    sort(final_test, final_test + number, cmp);
    // qsort(final_test, number, sizeof(final_test[0]), Local_Rank);
    for (int i = 0; i < number; i++)
    {
        if(i != 0 && final_test[i].score == final_test[i-1].score) {
            final_test[i].final_rank = final_test[i-1].final_rank;
        }
        else {
            final_test[i].final_rank = i+1;
        }
    }
    cout << number << endl;
    for (int i = 0; i < number; i++)
    {
        cout << final_test[i].registration_number << " ";
        cout << final_test[i].final_rank << " " << final_test[i].location_number << " ";
        cout << final_test[i].local_rank << endl;
    }
    return 0;
}