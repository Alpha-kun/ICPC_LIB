#include<bits/stdc++.h>


using namespace std;


void bfs(vector<int>& G[n+1]){
    
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    int dist[n+1];
    memset(dist,0,sizeof(dist));

    list<int> q;
    q.push_back(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(!visited[v]){
                visited[v]=true;
                q.push_back(v);
                dist[v]=dist[u]+1;
            }
        }
    }
}