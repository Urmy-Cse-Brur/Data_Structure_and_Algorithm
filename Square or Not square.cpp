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
    long long int i, j, p, n, first, last, mid, t, f, s;
    cin>>t;
    while(t--){
        cin>>n;
        s=sqrt(n);f=0;
        if(s*s==n){
            cout<<"Yes"<<endl;
            continue;
        }
        for(i=s;i>=0;i--){
            first=0;last=i;
            while(first<=last){
                mid=(first+last)/2;
                if(pow(mid,2)+pow(i,2)==n){
                    f=1;break;
                }
                else if(pow(mid,2)+pow(i,2)>n)
                    last=mid-1;
                else
                    first=mid+1;
            }
        }
        if(f)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}