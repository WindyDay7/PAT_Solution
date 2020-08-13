#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

const long long mod = 1e9+7;

long long pw(int number)
{
    long long result = 1;
    for (int i = 0; i < number; i++)
    {
        result = (result*2)%mod;
    }
    return result;
}

int main()
{
    int N = 0;
    cin >> N;
    long long result = 1, temp = 1;
    for (int i = 0; i < N; i++)
    {
        result = (result%mod * (N-i)) % mod;
    }
    temp = (pw(N-1)) % mod;
    temp = (result - temp + mod)%mod; 
    cout << temp << endl;
    return 0;
}