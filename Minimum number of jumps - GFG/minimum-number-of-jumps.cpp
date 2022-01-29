// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:

    int minJumps(int arr[], int n){
    queue<pair<int, int>> q;
    q.push({0,0});
    arr[0]*=-1;
    int trav = 0;
    while(q.size())
    {
        pair<int, int> p = q.front();
        q.pop();
        if(p.first == n-1)
            return p.second;
        int m;
        if(abs(arr[p.first])>=n || abs(arr[p.first]) + p.first >=n)
            m = n-1;
        else
            m = abs(arr[p.first]) + p.first;
        for(int i =max(trav, p.first + 1); i<=m;i++)
        {
            if(arr[i]>=0)
            {
                arr[i]*=-1;
                q.push({i, p.second+1});
            }
        }
        trav = max(trav, m);
    }
    return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends