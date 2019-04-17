/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>

using namespace std;

void print(int A[], int size);

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0,j = 0;

    for(k=l; ; k++){
        if(L[i]<R[j] && i<n1)
            arr[k] = L[i++];
        else if(j<n2)
            arr[k] = R[j++];
        else
            break;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
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
    int arr[] = {12, 11, 13, 5, 6, 7, -3, 100, 77, 17, 37, -10, 16};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array: " << endl;
    print(arr, n);

    mergeSort(arr, 0, n-1);

    cout << endl << "Sorted array: " << endl;
    print(arr, n);
    return 0;
}


