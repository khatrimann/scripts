#include<iostream>

using namespace std;

class MergeSort
{
    public:
        MergeSort(int *arr, int size)
        {
            a = arr;
            mergeSort(a, 0, size-1);
        }

        void printSortedArray(int a[], int size)
        {
            cout<<"The sorted array is: ";
            for(int i=0;i<size;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }

    private:
        int *a;
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
};

int main()
{
    int a[] = {98, 26, 95, 46, 19, 77};
    int size = sizeof(a)/sizeof(int);
    MergeSort to_be_sorted_array(a, size);
    to_be_sorted_array.printSortedArray(a, size);
    return 0;
}