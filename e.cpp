#include <bits/stdc++.h>
using namespace std;


int main() {

    int n,m;
    cin>>n>>m;


    vector<vector<int>> allocation(n,vector<int> (m));
    vector<vector<int>> maximum(n,vector<int> (m));
    vector<int> available(m);
    vector<int> instances(m);


    vector<vector<int>> need(n,vector<int> (m));

    for(int i=0;i<m;i++){
        int x;
        cin>>x;

        available[i] = x;
        instances[i] = x;


    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;

            allocation[i][j] = x;
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;

            maximum[i][j] = x;
        }

    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            available[j] -= allocation[i][j];
            
        }

    }



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j] = maximum[i][j]-allocation[i][j];
        }


    }

    vector<int> visited(n,0);
    vector<int> order;


    bool allDone = false;




    while(!allDone){

        for(int i=0;i<n;i++){

            bool done = true;
            for(int j=0;j<m;j++){
                if(need[i][j] > available[j]){
                    done = false;
                    break;
                }

            }

            if((done==true )&& (visited[i]==0)){
                visited[i] = 1;
                order.push_back(i);
                for(int j=0;j<m;j++){
                    available[j] += allocation[i][j];
                }

            }



        }

        bool okay = true;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                okay = false;
                break;
            }
        }

        if(okay){
            allDone = true;
        }

    }

    for(int i=0;i<n;i++){
        cout<<"P"<<order[i]<<" "<<endl;
    }

    



    
}