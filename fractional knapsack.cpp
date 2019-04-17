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

typedef struct item item;

bool compare(item a, item b)
{
  return (a.p/a.w)> (b.p/b.w);
}

int main()
{
  int N, W;

  cout << "Enter number of items and maximum weight: " << endl;
  cin >> N >> W;

  cout << "Enter items :" << endl;
  for(int i=0; i<N; i++){
    cin >> items[i].w >> items[i].p;
  }

  sort(items, items+N, compare);


  double weight=0, price=0, remainder;
  int j;

  for(int i=0; i<N; i++){

    if(weight+items[i].w<=W){
        weight+=items[i].w;
        price += items[i].p;
    }
    else{
        remainder = W - weight;
        j = i;
        break;
    }

  }

      double x;
      x= (items[j].p)*remainder;
      x = x/(items[j].w);
      price+=x;


   cout << "Maximum profit = " << price << endl;


  return 0;
}

/*

3 10
6 4
5 5
3 4

2 7
6 6
14 7

*/
