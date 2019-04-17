/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int WHITE=1, GREY=2, BLACK=3, color[100];
vector<int> adj[100], reverseAdj[100], components[100], t;
stack<int> s;

void dfs(int u)
{
  color[u] = GREY;

  for(vector<int>:: iterator i=adj[u].begin(); i!=adj[u].end(); i++){
     int v = *i;
     if(color[v] == WHITE){
        dfs(v);
     }
  }

  color[u] = BLACK;
  s.push(u);
}

void dfs_reverse(int u)
{
  color[u] = GREY;

  //cout << u << " ";
  t.push_back(u);

  for(vector<int>:: iterator i=reverseAdj[u].begin(); i!=reverseAdj[u].end(); i++){
     int v = *i;
     if(color[v] == WHITE){
        dfs_reverse(v);
     }
  }
  color[u] = BLACK;
}

void initialize(int  v)
{
  for(int i=0; i<v; i++)
    color[i] = WHITE;
}

void printSCCS(int c)
{
  for(int i=0; i<c; i++){
    for(vector<int>::iterator j=components[i].begin(); j!=components[i].end(); j++){
      cout << *j << " ";
    }
      cout << endl;
  }
}

void computeSCCS(int v)
{
  for(int i=0; i<v; i++){
     if(color[i]==WHITE)
        dfs(i);
  }

  initialize(v);

  int c=0;
  while(!s.empty()){
    int u = s.top();
    s.pop();

    if(color[u]==WHITE){
       dfs_reverse(u);
       components[c] = t;
       t.clear();
       c++;
    }
  }

  printSCCS(c);

  cout << endl << "Number of strongly connected components = " << c << endl;
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
     reverseAdj[y].push_back(x);
  }

  initialize(v);

  cout << endl << "Strongly Connected Components: " << endl << endl;
  computeSCCS(v);

  return 0;
}


/*
7

8

0 1
0 3
0 4
1 2
2 0
4 5
5 6
6 4

*/
