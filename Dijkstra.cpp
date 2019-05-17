#include<iostream>
#include<list>
using namespace std;

void addedge(int u, int v, int w, list<pair<int, int> > *adj){
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

int min_distance(bool visited[], int dist[]){
  int Min = INT_MAX, index = 0;
  for(int i = 0; i < 4; i++)
    if(dist[i] <= Min && !visited[i]){
      Min = dist[i];
      index = i;
    }
  return index;
}

void dijkstra(int s, list<pair<int, int> > *adj){
  bool visited[4] = {};
  int dist[4];
  for(int i = 0; i < 4; i++)
    dist[i] = INT_MAX;
  dist[s] = 0;
  for(int i = 0; i < 3; i++){
    int u = min_distance(visited, dist);
    visited[u] = true;
    for(list<pair<int, int> > :: iterator it = adj[u].begin(); it != adj[u].end(); it++){
      int v = (*it).first;
      int w = (*it).second;
      if(dist[u] != INT_MAX && !visited[v] && dist[v] > dist[u] + w)
        dist[v] = dist[u] + w;
    }
  }
  for(int i = 0; i < 4; i++)
    cout<<s<<" -- >"<<i<<" = "<<dist[i]<<endl;
}

int main(){
  list<pair<int, int> > *adj = new list<pair<int, int> >[4];
  addedge(0, 1, 5, adj);
  addedge(0, 2, 4, adj);
  addedge(1, 2, 3, adj);
  addedge(2, 3, 7, adj);
  dijkstra(0, adj);
}
