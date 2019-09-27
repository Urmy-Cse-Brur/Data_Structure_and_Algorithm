#include<bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <vector>
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

#define MAX 100
int parent[MAX];
int rankParent[MAX];

void intialize(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rankParent[i]=0;
    }
}

int findParent(int x){
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

void unionSet(int x, int y){
    int px=findParent(x);
    int py=findParent(y);
    if(px==py) return;

    if(rankParent[px] < rankParent[py])
        parent[px]=py;
    else if(rankParent[px]>rankParent[py])
        parent[py]=px;
    else{
        parent[py]=px;
        rankParent[px]++;
    }
}
int main()
{
    int n;
    cin>>n;
    intialize(n);
    unionSet(0, 1);
    unionSet(4, 2);
    unionSet(3, 1);
    unionSet(0, 3);
    for(int i=0;i<n;i++)cout<<"Node is "<<i<<" Parent is "<<parent[i]<<" Rank is "<<rankParent[i]<<endl;
    return 0;
}
