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

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root;

void insert(int value){
  //  struct Node *newNode=(struct Node*)malloc (sizeof(struct Node));
    struct Node *newNode= new Node();
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    if(root==NULL)
        root=newNode;
    else{
        struct Node *temp=root;
        while(true){
            if(newNode->data<=temp->data){
                if(temp->left==NULL){
                    temp->left=newNode;
                    break;
                }
                else
                    temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right=newNode;
                    break;
                }
                else
                    temp=temp->right;
            }
        }
    }
}

void inorder(struct Node *r){
    if(r==NULL) return;
    inorder(r->left);
    cout<<r->data<<endl;
    inorder(r->right);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    root=NULL;
    insert(55);
    insert(40);
    insert(80);
    insert(34);
    insert(28);
    insert(38);
    insert(60);
    insert(90);
    inorder(root);
    return 0;
}
