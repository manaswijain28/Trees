#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> dp(n+1,vector<int> (2,0));

    //yaha -1 as initial value lene ki zarurat nahi as hum every node se ek bar hi traverse karte hai.

    auto dfs = [&](int node, int parent, auto && self){
        dp[node][1] = arr[node];
        dp[node][0] = 0;

        for(auto &it : adj[node]){
            if(it != parent){
                self(it,node,self);
                dp[node][1] += dp[it][0];
                dp[node][0] += max(dp[it][0],dp[it][1]);
            }
        }
    }

    dfs(1,-1,dfs);

    cout<<max(dp[1][0],dp[1][1])<<endl;





    
}

/*
House Robber problem similar

Given a tree T of n nodes, where each node has Ci coins. You need to choose a subset of nodes s.t every pair of nodes in this s
subset is not connected by an edge. FInd the max number of coins you can get.

Idea :
Ya to hum kisi node ko pick kar sakte hai nahi 
if maine kisi node ko pick kiya then mai uske koi bhi child pick nahi kar sakti 
dp[i][1] = arr[i] + summation(dp[j][0]) , j = child 
if maine vo node pick nahi kiya then ya to uske chikd pick kar sakti hu ya nahi bhi, i will choose the one with the max answer
dp[i][0] = 0 + summation(max(dp[j][0],dp[j][1])) , j = child

*/
