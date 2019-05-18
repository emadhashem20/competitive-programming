#include <bits/stdc++.h>
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++) 

using namespace std;
typedef long long ll;
typedef pair <int , int> pii;



const double eps = 1e-10;
const int MAXN = 1e7+6;
const int MOD = 1e9 + 7;
int rk[MAXN], p[MAXN];
int getp(int a) {
    return (a == p[a] ? a : getp(p[a]));
}
void unite(int a, int b) {
    a = getp(a), b = getp(b);
    if(a == b) return;
    if(rk[a] < rk[b]) swap(a , b);
    p[b] = a;
    rk[a] += rk[b];
}
int main () {
    forn(i , 15) {
        rk[i] = 1;
        p[i] = i;
    }
    return 0;
}
