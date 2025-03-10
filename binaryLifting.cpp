//company queries 1 cses
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,q;
    cin>>n>>q;

    vector<ll> adj[n+1];
    for(int i=2;i<=n;i++){
        ll x;
        cin>>x;
        adj[x].push_back(i);
    }

    vector<vector<ll>> par(n+1,vector<ll>(20,0));


    function<void(ll,ll)> dfs = [&](ll node,ll parent)-> void{

        if(node == 1){
            for(int i=0;i<20;i++){
                par[node][i] = 0;
            }
        }else{
            par[node][0] = parent;
            for(int j=1;j<20;j++){

                par[node][j] = par[par[node][j-1]][j-1];
            }
        }

        for(auto &it:adj[node]){
            if(it != parent){
                dfs(it,node);
            }
        }

    };


    function<ll(ll ,ll)> kParent = [&](ll u, ll k)-> ll{
        for(int i=19;i>=0;i--){
            if((1<<i)&k){
                u = par[u][i];
                if(u == -1){
                    return -1;
                }
            }
        }

        return u;

    };

    dfs(1,1);


    for(int i=1;i<=q;i++){
        ll x,k;
        cin>>x>>k;

        ll ans = kParent(x,k);
        if(ans == 0){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }




    }



}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
