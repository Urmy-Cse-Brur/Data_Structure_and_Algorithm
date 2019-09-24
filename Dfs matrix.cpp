#include <bits/stdc++.h>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
int color[100010];
int a[100][100];


void dfsVisit (int x){
    color[x] = GRAY;
    for (int i = 1; i <= node; i++){
        if (a[x][i] == 1){
            if (color[i] == WHITE){
                dfsVisit(i);
            }
        }
    }
    color[x] = BLACK;
}

void dfs(){
    int i;
    for (i = 1; i <= node; i++)
        color[i] = WHITE;

    for (i = 1; i <= node; i++){
        if (color[i] == WHITE){
            dfsVisit(i);
        }
    }
}

int main ()
{
    int  i, c, t, v1, v2, n, edge;
    cin>>n>>edge;
    for(i=0;i<edge;i++)
        cin>>v1>>v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
    dfs();
    return 0;
}