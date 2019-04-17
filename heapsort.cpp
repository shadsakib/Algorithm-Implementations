/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>

using namespace std;

void maxHeapify(int A[], int i, int n)
{
  int largest, l, r;

  largest = i;
  l = 2*i+1;
  r = 2*i+2;

  if(A[largest]<A[l] && l<n)
     largest = l;

  if(A[largest]<A[r] && r<n)
     largest = r;

  if(largest != i) {
     swap(A[i], A[largest]);
     maxHeapify(A, largest, n);
  }

}

void buildMaxHeap(int A[], int n)
{
  for(int i=n/2 -1 ; i>=0; i--)
     maxHeapify(A, i, n);
}

void heapSort(int A[], int n)
{
   buildMaxHeap(A, n);

   for(int i=n-1; i>=1; i--){
       swap(A[0], A[i]);
       maxHeapify(A, 0, i);
   }
}

void printArray(int A[], int n)
{
 for(int i=0; i<n; i++)
     cout << A[i] << " ";

 cout << endl << endl;
}


int main()
{
   int arr[] = {-7, 5, 11, 22, -27, 2, 0, 13};
   int n = sizeof(arr)/sizeof(arr[0]);

   cout << "Initial array: " << endl;
   printArray(arr, n);

   heapSort(arr, n);

   cout << "Sorted array: " << endl;
   printArray(arr, n);

   return 0;
}
