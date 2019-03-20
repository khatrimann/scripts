
/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<iostream>

using namespace std;

int iteration = 1;
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    cout<<"\nIteration: "<<iteration<<endl;
    iteration++;
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    cout<<"\n(n1, n2) :: ("<<n1<<", "<<n2<<")\n";
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    cout<<"\nl = "<<l<<" and m = "<<m<<endl;
    for (i = 0; i < n1; i++) 
    {
        cout<<"\nl + i = "<<l+1<<endl;
        L[i] = arr[l + i];
    } 
    for (j = 0; j < n2; j++)
    {
        cout<<"\nm + 1 + j = "<<m+1+j<<endl; 
        R[j] = arr[m + 1+ j];
    } 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    cout<<"L is: ";
    for(int i=0;i<n1;i++)
        cout<<L[i]<<" ";
    cout<<endl;
    cout<<"R is: ";
    for(int i=0;i<n2;i++)
        cout<<R[i]<<" ";

    cout<<"\nArray arr[] is: \n";
    for(int i=0;i<k;i++)
        cout<<arr[i]<<" ";
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        //cout<<"\nBelongs to iteration: "<<iteration<<endl;
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
        cout<<"\nm = "<<m;
        cout<<"\nl = "<<l;
        cout<<"\nr = "<<r;
        // Sort first and second halves
        cout<<"\nSorting first Half...\n";
        cout<<"\nStarted first from "<<l<<" to "<<m<<endl;
        mergeSort(arr, l, m); 
        cout<<"\nSorted first Half!!\n";
        cout<<"\nSorting second Half...\n";
        cout<<"\nStarted second from "<<m+1<<" to "<<r<<endl;
        mergeSort(arr, m+1, r);
        cout<<"\nSorted second half!!\n";

        cout<<"\nMerging...\n";
        cout<<"\nm = "<<m;
        cout<<"\nl = "<<l;
        cout<<"\nr = "<<r;
        merge(arr, l, m, r);
        cout<<"\nMerged!!"; 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\n\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
