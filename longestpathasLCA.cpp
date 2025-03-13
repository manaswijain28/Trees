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


    vector<int> height(n+1,1);
    vector<int> maxht(n+1,0);

    function<void(int,int)> dfs = [&](int node,int parent)->void{
        pair<int,int> hts = {0,0};
        for(auto &it: adj[node]){
            if(it != parent){
                dfs(it,node);
                height[node] = max(height[node],height[it]+1);

                if(height[it]>=hts.first){
                    hts = {height[it],hts.first};
                }else if(height[it]>hts.second){
                    hts = {hts.first,height[it]};
                }
            }
        }
        // cout<<node<<" "<<hts.first<<" "<<hts.second<<endl;

        maxht[node] = hts.first+hts.second+1;
    };

    dfs(1,1);

    
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<maxht[i]<<endl;
    }

    
    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
