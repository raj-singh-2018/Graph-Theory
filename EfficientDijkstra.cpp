#include<iostream>
#include<list>
#include<queue>
using namespace std;

void addedge(int u, int v, int w, list<pair<int, int> > *adj){
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

void dijkstra(int s, list<pair<int, int> > *adj){
  bool visited[4] = {};
  int dist[4];
  for(int i = 0; i < 4; i++)
    dist[i] = INT_MAX;
  priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push(make_pair(0, s));
  dist[s] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    visited[u] = true;
    for(list<pair<int, int> > :: iterator it = adj[u].begin(); it != adj[u].end(); it++){
      int v = (*it).first;
      int w = (*it).second;
      if(!visited[v] && dist[u] != INT_MAX && dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  cout<<"DISTANCE OF ALL VERTICES FROM SOURCE: "<<endl;
  for(int i = 0; i < 4; i++)
    cout<<s<<" --> "<<i<<" "<<dist[i]<<endl;
}

int main(){
  list<pair<int, int> > *adj = new list<pair<int, int> >[4];
  addedge(0, 1, 5, adj);
  addedge(0, 2, 4, adj);
  addedge(1, 2, 3, adj);
  addedge(2, 3, 7, adj);
  dijkstra(0, adj);
}
