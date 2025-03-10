#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin>>n;
    // cout<<n<<endl;

    set<ll> distinctColors[n+1];
    vector<ll> adj[n+1];
    vector<ll> answer(n+1);

    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        ll aa,b;
        cin>>aa>>b;

        adj[aa].push_back(b);
        adj[b].push_back(aa);
    }


    function<void(ll, ll)> dfs = [&](ll node,ll parent)->void{
        distinctColors[node].insert(a[node]);

        for(auto &it : adj[node]){
            if(it != parent){
                dfs(it,node);
                if(distinctColors[it].size()>distinctColors[node].size()){
                    swap(distinctColors[it],distinctColors[node]);
                }

                for(auto &i : distinctColors[it]){
                    distinctColors[node].insert(i);
                }
            }
        }

        answer[node] = distinctColors[node].size();
    };

    dfs(1,-1);

    for(int i=1;i<=n;i++){
        cout<<answer[i]<<" ";
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
