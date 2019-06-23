#include <bits/stdc++.h>
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long ll;
typedef pair <int , int> pii;
typedef pair <ll , ll> pll;



const double eps = 1e-10;
const int MAXN = 1e7+6;
const int MOD = 1e9 + 7;
int dx[] = {1 , -1 , 0 , 0};
int n, k;
int dp[100][100];
int solve(int rk, int rem) {
    if(rk == k) {
        if(rem == 0) return 1;
        else return 0;
    }
    int &ret = dp[rk][rem];
    if(~ret) return ret;
    ret = 0;
    for(int i = 1; i <= rem; i++) {
        int sol = solve(rk + 1, rem - i) * i;
        ret = max(ret , sol);
    }
    return ret;
}
int main () {
    cin >> n >> k;
    memset(dp , -1 , sizeof dp);
    cout << solve(0 , n);
    return 0;
}
