// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<int> x;
    k--;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            x.push_back(mat[i][j]);
        }
    }
    sort(x.begin(), x.end());
    int l = 0, h = n*n-1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(mid == k)
            return x[mid];
        if(mid < k)
            l = mid+1;
        else
            h = mid-1;
    }
    return -1;
  //Your code here
}
