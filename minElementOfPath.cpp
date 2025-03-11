#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5+1;
const int M = 20;

vector<int> adj[N];
int depth[N];
pair<int,int> par[N][M];
int arr[N];

void dfs(int node,int parent){

    for(int i=0;i<M;i++){
        par[node][i] = {0,INT_MAX};
    }

    par[node][0] = {parent,min(arr[node],arr[parent])};
    depth[node] = depth[parent]+1;

    for(int j=1;j<20;j++){
        par[node][j] ={par[par[node][j-1].first][j-1].first,min(par[par[node][j-1].first][j-1].second,par[node][j-1].second)};
    }

    for(auto &it : adj[node]){
        if(it != parent){
            dfs(it,node);
        }
    }



}
int minDistance(int x,int y){
    if(x == y){
        return x;
    }

    if(depth[x]<depth[y]){
        swap(x,y);
    }

    int mn = min(arr[x],arr[y]);

    int diff = depth[x]-depth[y];

    for(int i=19;i>=0;i--){
        if((1<<i)&diff){
            x = par[x][i].first;
            mn = min(mn,par[x][i].second);
        }
    }

    for(int i=19;i>=0;i--){
        if(par[x][i].first != par[y][i].first){

            mn = min(mn,min(par[x][i].second,par[y][i].second));
            x = par[x][i].first;
            y = par[y][i].first;

        }
    }

    return (x!=y ? min(mn,par[x][0].second):mn);





}

void solve() {
    int n,q;
    cin>>n>>q;


    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        adj[a].push_back(i);

    }

    dfs(1,1);


    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        cout<<minDistance(l,r)<<endl;
    }

    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
