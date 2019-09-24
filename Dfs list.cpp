#include <bits/stdc++.h>

using namespace std;

bool vis[100010];

void dfs (int n, vector <int> adj[ ]){
 if (!vis[n]){
    vis[n] = true;
    for (int i = 0; i < adj[n].size(); i++){
        if (!vis[adj[n][i]]){
            dfs(adj[n][i], adj);
        }
      }
    }
}

int main(){
    int t, n, e, c;
    vector <int> adj[100010];
    cin >> n >> e;
    for (int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) dfs(i, adj);
    return 0;
}