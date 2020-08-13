#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define max_NUM 200010
int n,num[12],p[10][10],ans;
char ch[max_NUM];

int main()
{
    int test = 0; cin >> test;
    int length = 0, temp = 0, result = 0;
    while (test--)
    {
        memset(p, 0, sizeof(p));
        scanf("%s", ch);
        length = strlen(ch);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < length; i++)
        {
            num[ch[i] - '0'] += 1;
        }
        for (int i = 0; i < length; i++)
        {
            temp = ch[i] - '0';
            for (int j = 0; j < 10; j++)
            {
                if(j == temp) {
                    continue;
                }
                if(p[j][temp]%2 != 0) {
                    p[j][temp] += 1;
                }
                if(p[temp][j]%2 == 0) {
                    p[temp][j] += 1;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            result = max(result, num[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(i!=j) {
                    result = max(result, p[i][j]/2 * 2);
                }
            }
            
        }
        cout << length-result << endl;
    }
    
    return 0;
}