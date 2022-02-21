// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int sum(int freq[], int x, int y)
    {
        int sum = 0;
        for(int i=x;i<=y;i++)
        {
            sum += freq[i];
        }
        return sum;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        int dp[n][n];
        for(int i = 0;i<n;i++)
        {
            dp[i][i] = freq[i];
        }
        for(int l=1;l<=n-1;l++)
        {
            for(int i = 0;i<n;i++)
            {
                if(i+l >=n)
                    break;
                int j = i + l;
                int mx = 1e9;
                int s = sum(freq, i, j);
                //cout<<s<<endl;
                for(int r = i;r<=j;r++)
                {
                    mx = min(mx, ((r>i)?dp[i][r-1]:0) + ((r<j)?dp[r+1][j]:0) + s);
                }
                dp[i][j] = mx;
            }
        }
        return dp[0][n-1];
        // code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends