#include<iostream>

using namespace std;

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i=0;i<n1;i++)
        L[i] = a[l+i];
    for(int j=0;j<n2;j++)
        R[j] = a[m+1+j];

    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;        
    }

    while(i<n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;

        mergeSort(a, l, m);
        mergeSort(a, m+1, r);

        merge(a, l, m, r);
    }
}

void print(int a[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[] = {19, 32, 92, 43, 83, 56};
    int size = sizeof(a)/sizeof(a[0]);
    mergeSort(a, 0, size-1);
    print(a, size);
    return 0;
}