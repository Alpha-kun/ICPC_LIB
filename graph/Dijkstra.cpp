#include<bits/stdc++.h>
#define INF 0xfffffffff

using namespace std;

typedef long long ll;
typedef pair<int,int> prii;
typedef pair<ll,int> prli;


void testcase(vector<prii>& G[n+1]){

    vector<ll> dist(n+1,INF);
    priority_queue <prli, vector<prli>, greater<prli>> pq;
    dist[s]=0;
    pq.push(make_pair(dist[s],s));
    while(!pq.empty()){
        int u=pq.top().second;
        ll sd=pq.top().first;
        pq.pop();
        if(sd!=dist[u]) continue;
        for(int i=0;i<G[u].size();i++){
            prii edge=G[u][i];
            int v=edge.first;
            if(dist[u]+edge.second<dist[v]){
                dist[v]=dist[u]+edge.second;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}