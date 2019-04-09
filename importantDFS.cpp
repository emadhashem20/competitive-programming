#include <bits/stdc++.h>
#define ll long long

using namespace std;
int const MAXN = 1e6 + 5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, arr[MAXN], ans = 0, reds = 0, blues = 0;
vector <int> adj[MAXN];
bool vis[MAXN];

pair <int , int> dfs(int u, int p) {
    int red = (arr[u] == 1);
    int blue = (arr[u] == 2);
    for(int i = 0; i < adj[u].size(); i++) {
            if(adj[u][i] != p) {
               pair<int , int> t =  dfs(adj[u][i] , u);
               ans += (t.first == reds && t.second == 0);
               ans += (t.second == blues && t.first == 0);
               red += t.first;
               blue += t.second;
            }
    }
    return {red , blue};
}
int main()
{
   cin >> n;
   for(int i = 0; i < n; i++) {
        cin >> arr[i];
        blues += (arr[i] == 2);
        reds += (arr[i] == 1);
   }
   int u , v;
   for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);

   }
   ans = 0;
   dfs(0 , -1);
   cout << ans;
   return 0;
}
