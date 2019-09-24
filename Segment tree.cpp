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

int a[10010];
int tree[30010];
void segment(int node, int b, int e){
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;
    segment(left,b,mid);
    segment(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j){
    if(i>e || j<b) return 0;
    if(i<=b && j>=e) return tree[node];
    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;
    int p1=query(left, b, mid, i, j);
    int p2=query(right, mid+1, e, i, j);
    return p1+p2;
}

void update(int node, int b, int e, int i, int newvalue){
    if(i>e || i<b) return;
    if(i<=b && i>=e) {
        tree[node]=newvalue;
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node]=tree[left]+tree[right];  
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    int n, i, j;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    segment(1,1,n);
    i=7;j=4;
    update(1, 1, n, i, j);
    i=1;j=7;
    cout<<query(1,1,n,i,j)<<endl;
    return 0;
}
