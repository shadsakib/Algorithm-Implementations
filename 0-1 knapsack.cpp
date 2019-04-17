/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>

using namespace std;

struct item
{
 int w, p;
}items[100];

int ks[100][100];

int knapsack(int n, int w)
{
  for(int i=0; i<=n; i++)
    ks[i][0] = 0;

  for(int i=0; i<=w; i++)
    ks[0][i] = 0;

  for(int i=1; i<=n; i++){

    for(int j=0; j<=w; j++){
        if(items[i].w <= j)
                ks[i][j] = max(items[i].p + ks[i-1][j-items[i].w], ks[i-1][j]);
        else
            ks[i][j] = ks[i-1][j];
    }

  }

  return ks[n][w];
}

int main()
{
  int n, w;
  cout << "Enter number of items and maximum weight: " << endl;
  cin >> n >> w;

  cout << "Enter items: " << endl;
  for(int i=1; i<=n; i++)
    cin >> items[i].w >> items[i].p;

  cout << "Maximum price: " << knapsack(n, w) << endl;

  return 0;
}


/*

2 7
6 6
14 7

3 10
6 4
5 5
4 4

3 9
6 6
5 5
4 4

4 10
5 18
2 9
4 12
6 25

*/

