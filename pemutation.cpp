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
// this code for permutation
// ans it is easy
int main () {
    vector <int> p = {0 , 1 , 2 , 3 , 4};
    do {
        for(int i = 0; i < 5; i++) {
            cout << p[i];
        }
        cout << endl;
    } while(next_permutation(p.begin() , p.end()));
    return 0;
}
