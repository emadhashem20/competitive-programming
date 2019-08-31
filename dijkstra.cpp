#include <bits/stdc++.h>
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long ll; //printf("%lld ", ll); to out put long
typedef pair <int , int> pii;
typedef pair <ll , ll> pll;



const double eps = 1e-10;
const int MAXN = 1e5+6;
const int MOD = 1e9 + 7;
const ll INF = 1e16+16;
const int OO = 1e9 + 5;
bool ODD(ll O) {return (O % 2 != 0);}
int gcd(ll a, ll b) {if(a == 0) return b; return gcd(b % a, a);}

int dx[] = {1, 0, -1 ,0 , -1 , 0};
int dy[] = {0, 1, 0, -1 , -1 , 0};
int pr[MAXN];
ll dis[MAXN];
struct cmp{
    bool operator () (pair <int , ll> a , pair <int , ll> b) {
        return a.S > b.S;
    }
};
vector <pair <int , ll> > adj[MAXN];
int t, n, m, s, x, fr[MAXN];
void dijk(int src) {
    priority_queue<pair<int, ll>, vector<pair<int, ll> >, cmp> q;

    forn(i , MAXN) dis[i] = INF;
    dis[src] = 0;
    
    q.push({src , 0});
    pr[src] = -1;
    while(!q.empty()) {
        pair <int , ll> cur = q.top();
        int node = cur.first;
        ll cost = cur.second;
        q.pop();
        if(dis[node] == cost) {
            for(auto it : adj[node]) {
                int enode = it.F;
                ll ecost = it.S;
                if(cost + ecost < dis[enode]) {
                    pr[enode] = node;
                    dis[enode] = cost + ecost;
                    q.push({enode , dis[enode]});
                }
            }
        }
    }
}
int main () {

    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        forn(i , m) {
            int u, v;
            ll w;
            scanf("%d%d%lld", &u, &v, &w);
            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        scanf("%d", &x);
        forn(i , x) {
            scanf("%d", &fr[i]);
        }
        scanf("%d", &s);
        dijk(s);
        ll ans = INF;
        forn(i , x) {
            ans = min(ans , dis[fr[i]]);
        }
        cout << (ans == INF ? -1 : ans) << endl;
        forn(i , n + 1) adj[i].clear();
    }


    return 0;
}
