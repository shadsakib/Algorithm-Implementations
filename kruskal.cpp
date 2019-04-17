/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge
{
 int a, b, w;
};

typedef struct edge edge;

vector<edge> edges;
int weightMST;
int par[100];

bool compare(edge a, edge b)
{
  return a.w <  b.w;
}

void initDisjointSets(int n)
{
 for(int i=0; i<n; i++)
    par[i] = i;
}

int findparent(int x)
{
  if(par[x] == x)
    return x;
  else
    return findparent(par[x]);
}

bool isSameSet(int x, int y)
{
  return findparent(x) == findparent(y);
}

void dsUnion(int x, int y)
{
  if(!isSameSet(x, y)){
     par[findparent(y)] = findparent(x);
  }
}

void kruskal(int v)
{
  // for maximum spanning tree
 //for(vector<edge>::iterator i=edges.begin(); i!=edges.end(); i++)
   //(*i).w *=-1;

  sort(edges.begin(), edges.end(), compare);

  initDisjointSets(v);

  for(vector<edge>::iterator i= edges.begin(); i!=edges.end(); i++){
     edge e = *i;
     par[e.a] = findparent(e.a);
     par[e.b] = findparent(e.b);

     if(par[e.a] != par[e.b]){
        //e.w = e.w*-1;;
        cout << e.a << "-" << e.b << " : " << e.w << endl;
        weightMST+= e.w;
        dsUnion(e.a, e.b);
     }
  }

}

int main()
{
  int v, e;

  cout << "Enter number of vertex: " << endl;
  cin >> v;
  cout << "Enter number of edges: " << endl;
  cin >> e;

  cout << "Enter the edges and their weights: " << endl;
  for(int i=1; i<=e; i++){
    edge x;
    cin >> x.a >> x.b >> x.w;
    edges.push_back(x);
  }

  cout << endl << "Edges of MST: " << endl;
  kruskal(v);

  cout << endl << "Weight of MST: " << weightMST << endl;

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
