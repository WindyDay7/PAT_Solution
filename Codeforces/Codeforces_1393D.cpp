#include <stdio.h>
#include <iostream>
#include <algorithm>
#define maxn 2010
using namespace std;
char s[maxn][maxn];
int dp[maxn][maxn];

int main(){
	int n = 0, m = 0, result = 0;
    cin >> n >> m;
    char temp = 0;
    result = n*m;
    for (size_t i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            temp = s[i][j];
            if(s[i-1][j-1] == temp && s[i-1][j] == temp && s[i-1][j+1] == temp && s[i-2][j] == temp) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                dp[i][j] = min(dp[i][j], dp[i-2][j]);
                dp[i][j] += 1;
            }
            result = dp[i][j] + result;
        }
    }
    cout << result << endl;
	return 0;
}