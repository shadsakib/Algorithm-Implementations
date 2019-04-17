/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int WHITE=1, GREY=2, BLACK=3;
int color[100];
vector<int> adj[100];
stack<int> s;

void dfs(int u)
{
  color[u] = GREY;

  for(vector<int>:: iterator i=adj[u].begin(); i!=adj[u].end(); i++){
     int v = *i;
     if(color[v] == WHITE)
        dfs(v);
  }

  color[u] = BLACK;
  s.push(u);
}

void toposort(int v)
{
  for(int i=0; i<v; i++){
     if(color[i] == WHITE)
        dfs(i);
  }

  cout << "Topologically sorted order: ";
  while(!s.empty()){
    cout << s.top() << (s.size()==1? "\n" : "->");
    s.pop();
  }
}

int main()
{
  int v, e;

  cout << "Enter the number of vertices: ";
  cin >> v;
  cout << endl << "Enter the number of edges: ";
  cin >> e;

  cout << endl << "Enter edges: " << endl;
  for(int i=0; i<e; i++){
     int x, y;
     cin >> x >> y;
     adj[x].push_back(y);
  }

  for(int i=0; i<v; i++)
    color[i] = WHITE;

  toposort(v);

  return 0;
}
