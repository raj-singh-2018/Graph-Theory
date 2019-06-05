#include<iostream>
#include<list>
#include<queue>
using namespace std;

void addedge(int u, int v, int k, list<pair<int, int> > *adj){
  adj[u].push_back(make_pair(v, k));
}

void dijkstra(int s, int d, list<pair<int, int> > *adj, int V){
  bool visited[V];
  int dist[V];
  for(int i = 0; i < V; i++){
    visited[i] = false;
    dist[i] = INT_MAX;
  }
  priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push(make_pair(0, s));
  dist[s] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    visited[u] = true;
    pq.pop();
    for(list<pair<int, int> > :: iterator it = adj[u].begin(); it != adj[u].end(); it++){
      int v = (*it).first;
      int w = (*it).second;
      if(!visited[v] && dist[u] != INT_MAX && dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  if(dist[d] == INT_MAX)
    cout<<"NO"<<endl;
  else
    cout<<dist[d]<<endl;
}

int main(){
  int t, v, k, a, b, c;
  cin>>t;
  for(int i = 0; i < t; i++){
    cin>>v>>k;
    list<pair<int, int> > *adj = new list<pair<int, int> > [v];
    for(int j = 0; j < k; j++){
      cin>>a>>b>>c;
      addedge(--a, --b, c, adj);
    }
    cin>>a>>b;
    dijkstra(--a, --b, adj, v);
  }
}
