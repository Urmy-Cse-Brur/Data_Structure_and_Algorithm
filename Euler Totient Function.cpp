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


int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    int n, t, i, ans;
    cin>>t;
    while(t--){
        cin>>n;
        ans=n;
        set <int> s;
        set <int> :: iterator it;
        while(n%2==0){
            n/=2;
            s.insert(2);
        }
        int sq=sqrt(n);
        for(i=3;i<=sq;i+=2){
            while(n%i==0){
                n/=i;
                s.insert(i);
            }
        }
        if(n!=1) s.insert(n);
        for(it=s.begin();it!=s.end();it++)ans-=(ans / *it);
        cout<<ans<<endl;
    }
    return 0;
}