#include <bits/stdc++.h>
using namespace std;
#define ll long long

//inline-outline property
//x se x ke bich me konse konse elements hai jo x ke subtree
//me hai hume mil jayenge.

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

    int x,y;
    cin>>x>>y;


    int time = 0;
    vector<int> in(n+1);
    vector<int> out(n+1);


    function<void(int,int)> dfs = [&](int node,int parent)->void{
        in[node] = time;
        time++;
        for(auto &it : adj[node]){
            if(it != parent){
                dfs(it,node);
            }
        }

        out[node] = time;
        time++;

    };

    dfs(1,-1);

    if(in[x]<in[y] && out[y]<out[x]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

    }
    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
