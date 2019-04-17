/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>
#include<algorithm>

using namespace std;

struct activity
{
 int stime, etime;
}a[100];

typedef struct activity activity;

bool compare(activity a, activity b)
{
  if(a.etime == b.etime)
    return a.stime<b.stime;
  else
    return a.etime<b.etime;
}

void activitySelection(int n)
{
  sort(a, a+n, compare);

  int count=1;
  activity curr = a[0];
  cout << "Activity " << curr.stime << "-" << curr.etime << endl;

  for(int i=1; i<n; i++)
  {
     if(a[i].stime > curr.etime){
        cout << "Activity " << a[i].stime << "-" << a[i].etime << endl;
        curr = a[i];
        count++;
     }
  }

  cout << "Maximum " << count << " activities can be done." << endl;
}

int main()
{
  int n;
  cout << "Enter number of activity: " << endl;
  cin >> n;

  cout << "Enter starting and finishing times: " << endl;
  for(int i=0; i<n; i++)
    cin >> a[i].stime >> a[i].etime;

  activitySelection(n);

 return 0;
}

/*

1 4
3 5
0 6
5 7
3 9
5 9
6 10
8 11
8 12
2 14
12 16


2 7
3 4
5 6
*/
