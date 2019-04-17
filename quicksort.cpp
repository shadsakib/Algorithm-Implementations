/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>

using namespace std;

void print(int A[], int size);

int partition(int arr[], int start, int end)
{
  int pivot = arr[end];
  int i = start-1;

  for(int j=start; j<=end-1; j++){
    if(arr[j] < pivot){
       i++;
       swap(arr[i], arr[j]);
    }

    //print(arr, 7);
  }

  swap(arr[i+1], arr[end]);

  //print(arr, 7);

  return i+1;
}

void quicksort(int arr[], int start, int end)
{
  if(start < end){
   int p = partition(arr, start, end);
   quicksort(arr, start, p-1);
   quicksort(arr, p+1, end);
  }
}

void print(int A[], int size)
{
    for (int i=0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
  int arr[] = {4,9,1, 8, 2, 3, 7};

  int n = sizeof(arr)/sizeof(arr[0]);

  print(arr, n);

  quicksort(arr, 0, n-1);

  print(arr, n);

  return 0;
}
