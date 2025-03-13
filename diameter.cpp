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


    vector<int> distance(n+1,0);

    function<void(int,int,int)> dfs = [&](int node,int parent,int dist)->void{
        distance[node] = dist;
        for(auto &it : adj[node]){
            if(it != parent){
                dfs(it,node,dist+1);
            }
        }
    };

    dfs(1,-1,0);

    int firstEnd = 0;
    for(int i=1;i<=n;i++){
        if(distance[firstEnd]<distance[i]){
            firstEnd = i;
        }
    }

    dfs(firstEnd,-1,0);

    int secondEnd = 0;
    for(int i=1;i<=n;i++){
        if(distance[secondEnd]<distance[i]){
            secondEnd = i;
        }
    }

    cout<<firstEnd<<" "<<secondEnd<<" "<<distance[secondEnd]<<endl;



    
    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
