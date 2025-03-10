#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5+1;
const int M = 20;

vector<int> adj[N];
int depth[N];
int par[N][M];

void dfs(int node,int parent){

    par[node][0] = parent;
    depth[node] = depth[parent]+1;

    for(int j=1;j<20;j++){
        par[node][j] = par[par[node][j-1]][j-1];
    }

    for(auto &it : adj[node]){
        if(it != parent){
            dfs(it,node);
        }
    }



}
int lca(int x,int y){
    if(x == y){
        return x;
    }

    if(depth[x]<depth[y]){
        swap(x,y);
    }

    int diff = depth[x]-depth[y];

    for(int i=19;i>=0;i--){
        if((1<<i)&diff){
            x = par[x][i];
        }
    }

    for(int i=19;i>=0;i--){
        if(par[x][i] != par[y][i]){
            x = par[x][i];
            y = par[y][i];

        }
    }

    return (x!=y ? par[x][0] : x);





}

void solve() {
    int n,q;
    cin>>n>>q;

    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    dfs(1,0);



    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;

        int ans = lca(a,b);
        
        int fin = depth[a]-depth[ans]+depth[b]-depth[ans];
        cout<<fin<<endl;


    }

    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
