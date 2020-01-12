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
#define MOD 100000007
#define sz size()
const double pi=acos(-1.0);
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    int n, i, far=0, here=0;
    cin>>n;int a[n+1];
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++){
        here+=a[i];
        if(here<0)here=0;
        else if(here>far)far=here;
    }
    cout<<far<<endl;
    return 0;
}
