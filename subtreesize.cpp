#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {
    int n;
    cin>>n;

    vector<int> adj[n+1];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    vector<int> subtreesize(n+1,1);

    function<void(int,int)> dfs = [&](int node,int parent)->void{
        for(auto &it: adj[node]){
            if(it != parent){
                dfs(it,node);
                subtreesize[node] += subtreesize[it];
            }
        }
    };

    dfs(1,1);

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<subtreesize[i]<<endl;
    }
    
    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
