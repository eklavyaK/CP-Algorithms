#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************MAIN PROGRAM*******************************************************/


struct node{
    int bit;
    node *left, *right;
    node(int x): bit(x),left(NULL),right(NULL){}
};
void insert(long long num, node*head){
    for(int i=30;i>=0;i--){
        if((1LL<<i)&num){
            if(head->right==NULL){
                node* newNode = new node(1);
                head->right = newNode;
            }
            head = head->right;
        }
        else{
            if(head->left==NULL){
                node* newNode = new node(0);
                head->left = newNode;
            }
            head = head->left;
        }
    }
}
int findMaxXOR(long long num, node*head){
    long long ans = 0;
    for(int i=30;i>=0;i--){
        if((1LL<<i)&num){
            if(head->left==NULL){
                head = head->right;
            }
            else{
                ans += (1LL<<i);
                head = head->left;
            }
        }
        else{
            if(head->right==NULL){
                head = head->left;
            }
            else{
                ans += (1LL<<i);
                head = head->right;
            }
        }
    }
    return ans;
}
int main(){
    rapid_iostream;
    node* head = new node(0);
    int n, m; cin>>n>>m;
    vector<int> A(n),B(m);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<m;i++){
        cin>>B[i];
    }
    if(A.size()==0 || B.size()==0)return 0;
    for(int i=0;i<A.size();i++){
        insert(A[i],head);
    }
    int ans = 0;
    for(int i=0;i<B.size();i++){
        ans = max(ans,findMaxXOR(B[i],head));
    }
    cout<<ans<<endl;
    return 0;
}