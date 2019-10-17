#include<bits/stdc++.h>
#include <bitset>
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
int dx4[] = {1, -1, 0, 0};
int dy4[] = {0, 0, 1, -1};

char s[100][100];
int vis[100][100], r, c, level[100][100];

void bfs(int row, int col){
    queue <ii> q;
    q.push(ii(row, col));
    vis[row][col]=1;
    while(!q.empty()){
        ii top=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=top.ff+dx4[i];
            int y=top.ss+dy4[i];
            if(x>=0 && x<r && y>=0 && y<c && vis[x][y]==0){
                vis[x][y]=1;
                level[x][y]=level[top.ff][top.ss]+1;
                q.push(ii(x,y));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("int.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    int i, j;
    cin>>r>>c;
    for(i=0;i<r;i++)cin>>s[i];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(!vis[i][j]){
                bfs(i, j);
            }
        }
    }
    cout<<level[2][2];
    return 0;
}
