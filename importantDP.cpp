#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N = 2e5 + 5;
int const MOD = 1e9 + 7;
//int cnt = 0, cntnt_1 = 0, cnt_2 = 0;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
int n, l, r, dp[N][4];
int cnt(int x, int limit) {
    int ret = limit / 3;
    if(limit % 3 >= x && x){
        ++ret;
    }
    return ret;
}
ll cnt(int x) {
    return cnt(x , r) - cnt(x , l - 1);
}

int solve(int i, int mod) {
    if(i == n)
        return (mod == 0);
    int &ret = dp[i][mod];
    if(ret != -1)
        return ret;
    ret = (solve(i + 1 , (mod + 1) % 3) * cnt(1)) % MOD;
    ret = (ret + solve(i + 1 , mod % 3) * cnt(0)) % MOD;
    ret = (ret + solve(i + 1 , (mod + 2) % 3) * cnt(2)) % MOD;
    return ret;
}
int main()
{
    cin >> n >> l >> r;
    memset(dp , -1 , sizeof(dp));
    //cout << cnt(0) << " " << cnt(1) << " " << cnt(2);
    cout << solve(0 , 0);
    return 0;
}
