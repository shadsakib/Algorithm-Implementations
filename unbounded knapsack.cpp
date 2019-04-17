/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<algorithm>

using namespace std;

struct item
{
  int w, p;
}items[100];

int ks[100];

typedef struct item item;


void dp(int n, int w)
{
    for(int i=0; i<=w; i++){
        for(int j=0; j<n; j++){
            if(items[j].w<=i)
                ks[i] = max(ks[i], ks[i-items[j].w] + items[j].p);
        }
    }
}


int main()
{
  int N, W;
  cout << "Enter number of items and maximum weight: " << endl;
  cin >> N >> W;

  cout << "Enter items :" << endl;
  for(int i=0; i<N; i++)
    cin >> items[i].w >> items[i].p;


  dp(N, W);
  cout << "Maximum profit = " << ks[W] << endl;

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
