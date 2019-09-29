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

int merge(int a[ ], int start, int mid, int end){
    int temp[100], i, j, index=0, k;
    i=start; j=mid+1;
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            temp[index]=a[i];
            index++;i++;
        }
        else{
            temp[index]=a[j];
            index++; j++;
        }
    }
    while(i<=mid){
        temp[index]=a[i];
        index++; i++;
    }
    while(j<=end){
        temp[index]=a[j];
        index++;j++;
    }
    for(i=start, k=0;i<=end;i++){
        a[i]=temp[k];
        k++;
    }
}

void divide(int a[ ], int start, int end){
    int mid;
    if(end<=start){
        return;
    }
    else{
        mid=(start+end)/2;
        divide(a, start, mid);
        divide(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    int n, a[100], start, end, i;
    cin>>n;
    start=0, end=n-1;
    for(i=0;i<n;i++) cin>>a[i];
    divide(a, start, end);
    for(i=0;i<n;i++)cout<<a[i]<<endl;
    return 0;
}
