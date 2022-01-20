// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int fin_arr[r-l+1];
         int i = l, k=0, j = m+1;
         while(i<=m && j<=r)
         {
             if(arr[i]<arr[j])
                fin_arr[k++] = arr[i++];
            else
                fin_arr[k++] = arr[j++];
         }
        while(i<=m)
        {
            fin_arr[k++] = arr[i++];
        }
        while(j<=r)
        {
            fin_arr[k++] = arr[j++];
        }
        for(int i = l;i<=r;i++)
            arr[i] = fin_arr[i-l];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //cout<<l<<" "<<r<<endl;
        if(l>=r)
            return;
        if(l+1==r)
            {
                if(arr[l]>arr[r])
                {
                    int t = arr[l];
                    arr[l] = arr[r];
                    arr[r] = t;
                }
                return;
            }
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
        // for(int i = l;i<=r;i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends