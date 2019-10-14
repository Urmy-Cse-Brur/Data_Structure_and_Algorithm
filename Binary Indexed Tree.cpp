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
#define MOD 1000000007
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

#define MAX 100
int tree[MAX];
 int a[MAX];

void update(int idx, int val, int n){
	while(idx<=n){
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}

int query(int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx & -idx);
	}
	return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    int n, i;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a[i];
    	update(i, a[i], n);
    }
    cout<<query(5)-query(5-1);
    return 0;
}
