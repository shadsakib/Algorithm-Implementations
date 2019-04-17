/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

vector<int> dist(100, INT_MAX), parent(100, -1);
vector<pi> adj[100];
vector<int> path[100];
bool pathExists;

void relax(int v, int u, int w)
{
  dist[v] = dist[u] + w;
}

void dijkstra(int s, int n)
{
  dist[s] = 0;

  priority_queue<pi, vector<pi> , greater<pi> > pq;

  pq.push(make_pair(0, s));

  // n = number of vertex
  while(n--){
    pi p = pq.top();

    pq.pop();
    int u = p.second;

    for(vector<pi>::iterator i=adj[u].begin(); i!=adj[u].end(); i++){
        int v = (*i).first;
        int weight = (*i).second;

        if(dist[v] > dist[u]+weight){
            relax(v, u, weight);
            pq.push(make_pair(dist[v], v));
            parent[v] =u;
        }
    }

  }

}

void getShortestPath(int x, int i)
{
  if(x==0){
    path[i].push_back(0);
    return;
  }
  if(x==-1){
    pathExists = false;
    return;
  }

  getShortestPath(parent[x], i);
  if(pathExists) path[i].push_back(x);
}

void printShortestPath(int d)
{
  pathExists = true;
  getShortestPath(d, d);

  if(!pathExists){
    cout << "No path." << endl;
    return;
  }

  cout << "Shortest Path: ";
  for(vector<int>::iterator i=path[d].begin(); i!=path[d].end(); i++)
    cout << *i << (i==--path[d].end()? "" : "->");

  cout << endl << "Cost: " << dist[d] << endl;
}

int main()
{
  int v, e;

  cout << "Enter number of vertex: " << endl;
  cin >> v;

  cout << "Enter number of edges: " << endl;
  cin >> e;

  cout << "Enter edges: " << endl;
  for(int i=1; i<=e; i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back(make_pair(b, w));
  }

  dijkstra(0, v);

  int d;
  cout << endl << "Enter destination vertex: ";
  cin >> d;
  printShortestPath(d);

  return 0;
}


/*

4

5

0 1 10
1 2 20
1 3 40
2 3 15
3 0 50

*/
