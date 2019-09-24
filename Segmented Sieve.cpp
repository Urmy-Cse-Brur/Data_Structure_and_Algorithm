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

#define N 32000
bool a[N];
vi prime;

void sieve ( ){
     int i, j, s;
     for(i=0;i<N;i++)a[i]=true;
     s=sqrt(N);
     for (i=3;i<=s;i++){
        if (a[i]==true){
            for (j=i*i;j<=N;j+=i)
                a[j]=false;
        }
    }
    prime.pb(2);
    for(i=3;i<=N;i+=2){
        if(a[i]) prime.pb(i);
    }
}

void segSieve(long long int l, long long int r){
    bool a[r-l+1];
    long long  i, j, base,cp;
    for(i=0;i<r-l+1;i++) a[i]=true;
    if(l==1) a[0]=false;
    for(i=0;prime[i]*prime[i]<=r;i++){
        cp=prime[i];
        base=(l/cp)*cp;
        if(base<l) base+=cp;
        for(j=base;j<=r;j+=cp){
            a[j-l]=false;
        }
        if(base==cp) a[base-l]=true;
    }
    for(i=0;i<r-l+1;i++){
        if(a[i]) cout<<i+l<<endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    long long int l, r, t;
    sieve();
    cin>>l>>r;
    segSieve(l, r);
    return 0;
}
