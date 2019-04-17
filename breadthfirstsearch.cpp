/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int WHITE = 1, GRAY = 2, BLACK = 3;
int color[100], parent[100], dist[100];
vector<int> adj[100];

void bfs(int s)
{
  color[s] = GRAY;

  queue<int> q;

  q.push(s);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(vector<int>::iterator i=adj[u].begin(); i<adj[u].end(); i++){
        int v = *i;
        if(color[v] == WHITE){
           color[v]= GRAY;
           parent[v] = u;
           dist[v] = dist[u] + 1;
           q.push(v);
        }
    }
    cout << u << (q.empty()? "\n" :  "->");
    color[u] = BLACK;
  }

}

int main()
{
  int n, e, s;

  cout << "Enter number of vertexes: ";
  cin >> n;
  cout <<"\nEnter number of edges: ";
  cin >> e;

  cout << "\nEnter edges: " << endl;
  for(int i=0; i<e; i++){
       int x, y;
       cin >> x >> y;
       adj[x].push_back(y);
       adj[y].push_back(x);
  }

  for(int i=0; i<n; i++){
    parent[i] = i;
    dist[i] = 0;
    color[i] = WHITE;
  }

  cout << endl << "Enter starting vertex: ";
  cin >> s;

  cout << endl << "BFS: ";
  bfs(s);

  cout << endl << "Node\tParent\tDistance\tColor" << endl << endl;
  for(int i=0; i<n; i++)
    cout << i << "\t" << parent[i] << "\t" << dist[i] << "\t\t" << color[i] << endl;

  return 0;
}
