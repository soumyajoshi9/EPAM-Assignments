//Time Complexity:O(N)
// O(N) (nodes)+O(N) (edge traversals)=O(N)
// Space Complexity:O(N)
#include<bits/stdc++.h>
using namespace std;

void dfs (int node,int parent,unordered_map<int,vector<int>> &adj,vector<int> &key,int currxor,int &ans,int K){

    if (currxor >= K){
        ans++;
    }

    for (auto child: adj[node]){
        if (child != parent){
            dfs(child,node,adj,key,currxor ^ key[child-1],ans,K);
        }
    }
    
}

int main(){
    int N,K;
    cin>>N>>K;
    int ans = 0;
    int currxor=0;

    vector<int> key;
    for (int i=0;i<N;i++){
        int k;
        cin>>k;
        key.push_back(k);
    }

    unordered_map<int,vector<int>> adj;

    for (int j = 1; j < N; j++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1,adj,key,0,ans,K);
    cout<<ans;
    return 0;
}



