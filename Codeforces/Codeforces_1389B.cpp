#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 2e5 + 7;
int a[maxn],f[maxn];

int main() {
    int T;scanf("%d",&T);
    while(T--) {
        int n,k,z;scanf("%d%d%d",&n,&k,&z);
        f[0] = 0;
        for(int i = 1;i <= n;i++) {
            scanf("%d",&a[i]);
            f[0] = 0;
        }
        f[1] = a[1];
        int mx = 0;
        int ans = f[1];
        for(int i = 2;i <= k + 1;i++) { //最大的次数
            f[i] = f[i - 1] + a[i];
            // 最大的连续两个数字之和
            mx = max(mx,a[i] + a[i - 1]);
            // 从向左移动 0 次，到向左移动z次
            for(int j = 0;j <= z;j++) {
                // 如果我在当前位置 i，在 i中左右反复横跳 j 次， 肯定是在 mx 处反复横跳
                if(i + j * 2 <= k + 1) {
                    ans = max(ans,f[i] + mx * j);
                    // 单独处理最后一次往回跳动
                    if(j < z && i + j * 2 + 1 <= k + 1) {
                        ans = max(ans,f[i] + mx * j + a[i - 1]);
                    }
                }
            }
        }
    
        printf("%d\n",ans);
    }
    return 0;
}

//4 4 1
//1 1 9 2
//1 1 9 2 9

 
