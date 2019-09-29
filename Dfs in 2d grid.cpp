#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

int dx[]={-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1, -1, 1, -1, 0, 1};
int r, c;
char s[105][105];
bool visited[105][105];
using namespace std;

void dfs(int row, int col)
{
    for(int i=0; i<8; i++){
        int x=row+dx[i];
        int y=col+dy[i];
        if(!visited[x][y] && s[x][y]=='@'){
            visited[x][y]=true;
            dfs(x, y);
        }
    }
}

int main()
{
    int i, j;
    while(scanf("%d%d", &r, &c)==2)
    {
        if(r==0 && c==0) break;
        int cnt=0;
        for(i=0; i<r; i++) scanf("%s", &s[i]);
        memset(visited, false, sizeof(visited));
        for(i=0; i<r; i++){
            for(j=0; j<c; j++){
                if(s[i][j]=='@' && !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
