#include<iostream>
#include<list>
using namespace std;

//The end points of the edge are indicated by variables u, v and weight by w
void addedge(int u, int v, int w, list<pair<int, int> > *adj){
  //Adding a pair of vertex v and edge weight w to the array at index u
  adj[u].push_back(make_pair(v, w));
  //Adding a pair of vertex u and edge weight w to the array at index v as it is undirected
  adj[v].push_back(make_pair(u, w));
}

//Function to find the unvisited vertex with the minimum distance from the distance array
//The visited array is used to determine which vertices have been visited
//The distance array holds the distance from source to all other vertices
int min_distance(bool visited[], int dist[]){
  //The variable Min is used to hold the minimum distance encountered so far and is initially assigned a value INT_MAX
  //The variable index is used to hold the vertex number which is unvisited and has minimum distance
  int Min = INT_MAX, index = 0;
  //Loop through all vertices
  for(int i = 0; i < 4; i++)
  //In case there is a vertex whose distance is smaller than or equal to minimum distance so far
  //and it has not been visited so far
    if(dist[i] <= Min && !visited[i]){
      //Update the minimum distance
      Min = dist[i];
      //Update the index variable to hold the vertex number
      index = i;
    }
  //Return the vertex number with minimum distance
  return index;
}

void dijkstra(int s, list<pair<int, int> > *adj){
  //Using a boolean visited array of 4 vertices to keep a track of visited vertices, initially initialized to false
  //thereby representing that no vertices have been visited
  bool visited[4] = {};
  //Using a distance array of 4 vertices to hold the distances from source vertex to all other vertices
  int dist[4];
  //Initializing the distance vertices to maximum integer value
  for(int i = 0; i < 4; i++)
    dist[i] = INT_MAX;
  //Setting the distance of source vertex to zero
  dist[s] = 0;
  //Repeating the entire procedure Vertices - 1 times in this case 4 - 1 times
  for(int i = 0; i < 3; i++){
    //Finding the minimum distance from among all the unvisited vertices
    int u = min_distance(visited, dist);
    //Setting the vertex with minimum distance as visited
    visited[u] = true;
    //Checking all vertices adjacent to the vertex u
    for(list<pair<int, int> > :: iterator it = adj[u].begin(); it != adj[u].end(); it++){
      //The vertex is present as first part of the pair
      int v = (*it).first;
      //The weight is present as second part of the pair
      int w = (*it).second;
      //If the distance of the vertex u is not INT_MAX and the adjacent vertex to u has not been visited and
      //the distance to this vertex in the ditance array is more than the distance to vertex u and the current weight
      if(dist[u] != INT_MAX && !visited[v] && dist[v] > dist[u] + w)
      //We should update our array to hold the smaller distance
        dist[v] = dist[u] + w;
    }
  }
  //Loop used for printing distance from source to all vertices as present in our distance array
  for(int i = 0; i < 4; i++)
    cout<<s<<" -- >"<<i<<" = "<<dist[i]<<endl;
}

int main(){
  //The adjacency list representation of the graph is represented using a pair in a dynamic array of lists
  list<pair<int, int> > *adj = new list<pair<int, int> >[4];
  //Edge from vertex 0 to 1 and since it is undirected also representing edge from 1 to 0 with edge weight 5
  addedge(0, 1, 5, adj);
  //Edge from vertex 0 to 2 and since it is undirected also representing edge from 2 to 0 with edge weight 4
  addedge(0, 2, 4, adj);
  //Edge from vertex 1 to 2 and since it is undirected also representing edge from 2 to 1 with edge weight 3
  addedge(1, 2, 3, adj);
  //Edge from vertex 2 to 3 and since it is undirected also representing edge from 3 to 2 with edge weight 7
  addedge(2, 3, 7, adj);
  //Call to dijkstra function with the source vertex as 0
  dijkstra(0, adj);
}
