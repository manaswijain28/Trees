//counting paths cses
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3e5+1;
const int M = 20;


void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }


    vector<vector<int>> par(n+1,vector<int> (20,0));
    vector<int> depth(n+1);


    function<void(int,int)> dfs = [&](int node,int parent)->void{
        par[node][0] = parent;
        depth[node] = depth[parent]+1;


        for(int i=1;i<20;i++){
            par[node][i] = par[par[node][i-1]][i-1];
        }

        for(auto &it : adj[node]){
            if(it != parent){
                dfs(it,node);
            }
        }
    };

    function<int(int,int)> kParent = [&](int u,int k)->int{
        for(int i=19;i>=0;i--){
            if((1<<i)&k){
                u = par[u][i];
            }

        }

        return u;
    };

    dfs(1,0);

    function<int(int,int)> lca = [&](int x,int y)->int{
        if(x == y){
            return x;
        }

        if(depth[x]<depth[y]){
            swap(x,y);
        }


        int diff = depth[x] - depth[y];

        x = kParent(x,diff);

        for(int i=19;i>=0;i--){
            if(par[x][i] != par[y][i]){
                x = par[x][i];
                y = par[y][i];
            }
        }

        return (x!=y ? par[x][0]:x);
    };

    vector<int> arr(n+1,0);




    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        int ans = lca(x,y);
        // cout<<ans<<endl;
        arr[x]++;
        arr[y]++;
        arr[ans]--;
        arr[par[ans][0]]--;
    }

    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    function<void(int,int)> dfs2 = [&](int node,int parent)->void{

        for(auto &it : adj[node]){
            if(it != parent){
                dfs2(it,node);
                arr[node] += arr[it];
            }
        }

        // cout<<node<<" "<<arr[node]<<endl;
    };

    dfs2(1,0);

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;





    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
