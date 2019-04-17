/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

vector<pi> adj[100];
vector<int> dist(100, INT_MAX), parent(100, -1), path[100];
bool noPath;

void relax(int v, int u, int w)
{
  dist[v] = dist[u] + w;
}

bool bellmanford(int s, int v)
{
  dist[s] = 0;

  for(int i=0; i<v-1; i++){
    for(int j=0; j<v; j++){
        for(vector<pi>::iterator k=adj[j].begin(); k!=adj[j].end(); k++){
            int u = (*k).first;
            int w = (*k).second;

            if(dist[u] > dist[j]+w){
                relax(u, j, w);
                parent[u] = j;
            }
        }
    }
  }

  //check negative cycle
  for(int i=0; i<v; i++){
    for(vector<pi>::iterator j=adj[i].begin(); j!=adj[i].end(); j++){
        int u = (*j).first;
        int w = (*j).second;

        if(dist[u] > dist[i]+w) return false;
    }
  }

  return true;
}


void getShortestPath(int x, int i)
{
  if(x==0){
    path[i].push_back(0);
    return;
  }

  if(x==-1){
    noPath = true;
    path[i].clear();
    return;
  }

  getShortestPath(parent[x], i);
  path[i].push_back(x);
}

void printShortestPath(int d)
{
  noPath = false;
  getShortestPath(d, d);

  if(noPath){
    cout << "No path." << endl;
    return;
  }

  cout << "Shortest Path: ";
  for(vector<int>::iterator i=path[d].begin(); i!=path[d].end(); i++)
    cout << *i << (i== --path[d].end()? "" : "->");

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

  if(!bellmanford(0, v)){
    cout << "Negative cycle." << endl;
    return 0;
  }

  int d;
  cout << "Enter destination: " << endl;
  cin >> d;

  printShortestPath(d);

  return 0;
}


/*

5

5

0 1 1
0 2 5
1 2 1
2 3 6
3 4 10

********

5

5

0 1 1
0 2 5
1 2 1
2 0 -3
3 4 10

*/
