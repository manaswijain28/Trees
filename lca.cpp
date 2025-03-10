//company queries 2 cses
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,q;
    cin>>n>>q;

    vector<ll> adj[n+1];
    for(int i=2;i<=n;i++){
        ll a;
        cin>>a;
        adj[a].push_back(i);
    }

    vector<vector<ll>> par(n+1,vector<ll> (20,0));
    vector<ll> depth(n+1,0);

    function<void(ll,ll)> dfs = [&](ll node,ll parent)->void{

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



    };

    function<ll(ll,ll)> kParent= [&](ll u,ll k)->ll{
        for(int i=19;i>=0;i--){
            if((1<<i)&k){
                u = par[u][i];
            }
        }

        return u;

    };



    dfs(1,0);

    function<ll(ll,ll)> lca = [&](ll x,ll y)->ll{
        if(x == y){
            return x;
        }

        if(depth[x]<depth[y]){
            swap(x,y);
        }

        ll diff = depth[x]-depth[y];

        x = kParent(x,diff);

        for(int i=19;i>=0;i--){
            if(par[x][i] != par[y][i]){
                x = par[x][i];
                y = par[y][i];

            }
        }

        return (x!=y ? par[x][0] : x);





    };



    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;

        ll ans = lca(a,b);
        cout<<ans<<endl;


    }
   
    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
