/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<vector>
#define INF 9999999

using namespace std;

int dist[100][100];

void floydwarshall(int v)
{
  for(int k=0; k<v; k++)
    for(int i=0; i<v; i++)
       for(int j=0; j<v; j++)
          dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

void initialize(int v)
{
  for(int i=0; i<v; i++)
    for(int j=0; j<v; j++)
       dist[i][j] = (i==j? 0 : INF);
}

int main()
{
  int v, e;

  cout << "Enter number of vertex: " << endl;
  cin >> v;
  cout << "Enter number of edges: " << endl;
  cin >> e;

  initialize(v);

  cout << "Enter edges: " << endl;
  for(int i=1; i<=e; i++){
     int a, b, w;
     cin >> a >> b >> w;
     dist[a][b] = w;
  }

  floydwarshall(v);

  for(int i=0; i<v; i++){
    for(int j=0; j<v; j++)
      cout << "cost[" << i << "]" << "[" << j << "]" << " = " << dist[i][j]<< " ";
    cout << endl << endl;
  }

  return 0;
}

/*
4

5

0 1 2
1 2 3
2 3 1
1 3 7
3 0 10
*/
