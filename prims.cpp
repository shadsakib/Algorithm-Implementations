/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

vector<pi> adj[100];
vector<int> key(100, INT_MAX), parent(100, -1);
vector<bool> visited(100, false);
int weightMST;

void prims(int s)
{
  priority_queue<pi, vector<pi>, greater<pi> > pq;

  key[s] = 0;
  pq.push(make_pair(0, s));

  while(!pq.empty()){
     pi p = pq.top();
     pq.pop();

     int u = p.second;   // in priority queue, weight in first, vertex in second position

     if(visited[u]) continue;

     weightMST+=p.first;

     for(vector<pi>::iterator i=adj[u].begin(); i!=adj[u].end(); i++){
        int v = (*i).first;
        int w = (*i).second;   // in adjacency list, vertex in first, weight in second position

        if(!visited[v] && w < key[v]){
         key[v] = w;
         parent[v] = u;
         pq.push(make_pair(w, v));
        }

     }

     visited[u] = true;
  }

}

void printMST(int v)
{
  cout << endl << "Edges of MST: " << endl << endl;
  for(int i=0; i<v; i++)
    if(parent[i]!=-1) cout << parent[i] << " - " << i << " : " << key[i] << endl;

  cout << endl << "Weight of MST: " << weightMST << endl;
}

int main()
{
    int v, e, s;

    cout << "Enter number of vertex: " << endl;
    cin >> v;
    cout << "Enter number of edges: " << endl;
    cin >> e;

    cout << "Enter edges and their weights: " << endl;

    for(int i=1; i<=e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }

    cout << "Enter source: " << endl;
    cin >> s;

    prims(s);
    printMST(v);

  return 0;
}


/*
6

8

0 1 50
0 2 70
0 3 700
0 4 60
0 5 180
1 2 100
4 5 100
1 5 220

*/
