#include <bits/stdc++.h>
using namespace std;
int arr[15][15][15];
int ans[15][15][15];
int main()
{
    freopen("commandos.in","r",stdin);
    int t, f, y, x, h,n;
    scanf("%d", &t);
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        memset(ans,-1,sizeof ans);
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d %d %d %d", &f, &y, &x, &h);
            arr[f][y][x] += h;
        }
        ans[10][1][1] = 0;
        for (int fi = 10; fi >= 1; fi--)
        {
            for (int yi = 1; yi <= 10; yi++)
            {
                for (int xi = 1; xi <= 10; xi++)
                {
                    ans[fi][yi][xi] = max(max(ans[fi][yi][xi], ans[fi + 1][yi][xi]), max(ans[fi][yi - 1][xi], ans[fi][yi][xi - 1]));
                    ans[fi][yi][xi] += arr[fi][yi][xi];
                }
            }
        }
        printf("%d\n", ans[1][10][10]);
    }
 
    return 0;
}
// http://codeforces.com/gym/101147/problem/H المسالة
close
