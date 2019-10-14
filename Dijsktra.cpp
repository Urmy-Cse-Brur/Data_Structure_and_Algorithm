#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

#define inf 1000000000000 //2^30
vector <ii> adj[10000];
int parent[10000];
bool vis[10000];

void dijsktra(int source){
    ll distance[n+1];
    int i;
    for(i=1;i<=n;i++) {
        distance[i]=inf;
        parent[i]=-1;
    }
    priority_queue <ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, source));
    distance[source]=0;
    while(!q.empty()){
        int u=q.top().ss;
        q.pop();
        for(i=0;i<adj[u].sz;i++){
            if(distance[u]+adj[u][i].ss<distance[adj[u][i].ff]) {
                distance[adj[u][i].ff]=distance[u]+adj[u][i].ss;
                q.push(ii(distance[adj[u][i].ff], adj[u][i].ff));
                parent[adj[u][i].ff]=u;
            }
        }
    }
    for(i=1;i<=n;i++) cout<<source<<"-->"<<i<<"="<<distance[i]<<"parent="<<parent[i]<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    int n, e, i, v1, v2, w, source, temp, x;
    cin>>n>>e;
    for(i=0;i<e;i++){
        cin>>v1>>v2>>w;
        adj[v1].pb(ii(v2, w));
        adj[v2].pb(ii(v1, w));
    }
    cin>>source;
    dijsktra(source);
    return 0;
}
