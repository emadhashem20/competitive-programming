#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mx = 1e5+  5;
int t[4 * mx], lazy[4 * mx], arr[4 * mx];
void build(int tl, int tr, int v) {

    if(tl > tr) return;
    if(tl == tr) {
        t[v] = arr[tl];
        //cout << tl << " ";
        return;
    }

    int mid = (tl + tr) >> 1;
    build(tl , mid , (2 * v) + 1);
    build(mid + 1, tr, (2 * v) + 2);
    t[v] = t[(2 * v) + 1] + t[(2 * v) + 2];
}
int get_ans(int tl, int tr, int l, int r, int v) {
    if(lazy[v] != 0) {
        t[v] += (tr - tl + 1) * lazy[v];
        if(tr != tl) {
            lazy[(2 * v) + 1] += lazy[v];
            lazy[(2 * v) + 2] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(tl > tr || tr < l || tl > r) return 0;
    if(tl >= l && tr <= r) return t[v];
    int mid = (tl + tr) >> 1;
    return get_ans(tl , mid , l , r , (2 * v) + 1) + get_ans(mid + 1, tr, l, r, (2 * v) + 2);
}
void update(int tl, int tr, int l, int r, int n_v, int v) {
    if(tl > tr) return;
    if(lazy[v] != 0) {
        t[v] += (tr - tl + 1) * lazy[v];
        if(tr != tl) {
            lazy[(2 * v) + 1] += lazy[v];
            lazy[(2 * v) + 2] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(tl > tr || tr < l || tl > r) return ;
    if(tl >= l && tr <= r) {
        t[v] += (tr - tl + 1) * n_v;
        if(tr != tl) {
            lazy[(2 * v) + 1] += n_v;
            lazy[(2 * v) + 2] += n_v;
        }
        return;
    }
    int mid = (tl + tr) >> 1;
    update(tl , mid , l , r , n_v , (2 * v) + 1);
    update(mid + 1 , tr , l , r , n_v , (2 * v) + 2);
    t[v] = t[(2 * v) + 1] + t[(2 * v) + 2];

}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0 , n - 1, 0);
    cout << get_ans(0 , n - 1, 1 , 2 , 0);
    update(0 , n - 1 , 0 , 3 , 1 , 0);
    cout << endl << get_ans(0 , n - 1, 1 , 2 , 0);
    cout << endl << get_ans(0 , n - 1, 0 , 2 , 0);
    cout << endl << get_ans(0 , n - 1, 0 , 4 , 0);

    return 0;
}

