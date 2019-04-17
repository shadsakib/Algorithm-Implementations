/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> adj[100];
int color[100], WHITE=1, GREY=2, BLACK=3;
int dfsorder[100], j;

void dfs(int s)
{
  color[s] = GREY;
  dfsorder[j++] = s;

  for(vector<int>::iterator i=adj[s].begin(); i<adj[s].end(); i++){
     int v = *i;
     if(color[v] == WHITE)
       dfs(v);
  }

  color[s] = BLACK;

}


int main()
{
  int v,e ;

  cout << "Enter number of nodes: ";
  cin >> v;

  cout << endl << "Enter number of edges: ";
  cin >> e;

  cout << endl << "Enter edges:" << endl;

  for(int i=0; i<e; i++){
     int a, b;
     cin >> a >> b;
     adj[a].push_back(b);
     //adj[b].push_back(a);
  }

  for(int i=0; i<v; i++){
     color[i] = WHITE;
  }

  dfs(0);

  cout << endl << "DFS: ";
  for(int i=0; i<v; i++)
    cout << dfsorder[i] << (i==v-1? "\n" : "->");

  return 0;
}
