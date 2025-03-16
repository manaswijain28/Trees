//tree distance 2 cses
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ll n;
    cin >> n;
 
    vector<ll> adj[n + 1];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    vector<ll> sumdepths(n + 1);
    vector<ll> subtreesize(n + 1);
 
 
    function<ll(ll, ll, ll)> dfs = [&](ll node, ll parent, ll depth) -> ll {
        ll ans = depth;
        subtreesize[node] = 1;
        for (auto &it : adj[node]) {
            if (it != parent) {
                ans += dfs(it, node, depth + 1);
                subtreesize[node] += subtreesize[it];
            }
        }
        return ans;
    };
 
 
    function<void(ll, ll, ll)> reroot = [&](ll node, ll parent, ll ans) -> void {
        sumdepths[node] = ans;
        for (auto &it : adj[node]) {
            if (it != parent) {
                reroot(it, node, ans + n - 2 * subtreesize[it]);
            }
        }
    };
 
    ll answer = dfs(1, -1, 0);
    sumdepths[1] = answer;
    reroot(1, -1, answer);
 
    for (int i = 1; i <= n; i++) {
        cout << sumdepths[i] << " ";
    }
    cout << endl;
 
    return 0;
 
}
