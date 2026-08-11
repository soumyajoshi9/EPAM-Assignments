//Time Complexity:O(N+M)
// O(N) (BFS nodes)+O(M) (BFS edges)+O(N) (counting loop)=O(N+M)
// Space Complexity:O(N+M)
#include<bits/stdc++.h>
using namespace std;

int bfs(int N, int D, unordered_map<int,vector<int>> &adj){
    
    vector<int> dist(N+1, -1);
    queue<int> q;

    dist[1]=0;
    q.push(1);

    while(!q.empty()){

        int node = q.front();
        q.pop();

        for (auto child : adj[node]){
            if (dist[child] == -1){
                dist[child] = dist[node]+1;
                q.push(child);
            }
        }
    }

    int count = 0;
    for (auto value : dist){
        if(value != -1 && value <= D){
            count++;
        }
    }

    return count;
}

int main(){
    
    int N, M, D;
    cin >> N >> M >> D;

    unordered_map<int,vector<int>> adj;

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b ;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = bfs(N, D, adj);

    cout << ans << endl;
    
    return 0;
}
