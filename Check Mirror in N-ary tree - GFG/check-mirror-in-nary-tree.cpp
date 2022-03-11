// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int check(vector<vector<int>> &a, vector<vector<int>> &b, int root,int root2)
    {
        int x = 1;
        if(root!= root2 or a[root].size() != b[root2].size())
        {
           //cout<<root<<" "<<root2<<" "<<a[root].size()<<" "<<b[root2].size()<<endl;
            return false;
        }
        int n = a[root].size();
        for(int i = 0, j = n-1;i<n;i++, j--)
        {
            x &= check(a, b, a[root][i], b[root2][j]);
            if(x == 0)
            {
                //cout<<root<<" "<<root2<<" "<<a[root][i]<<" "<<b[root2][j]<<endl;
                return 0;
            }
        }
        return 1;
    }
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<int> k;
        vector<vector<int>> a(1e5+1, k), b(1e5+1,k);
        vector<int> x(n, 0), y(n, 0);
        int root = -1, root2 = -1;
        for(int i=0;i<2*e;i+=2)
        {
            a[A[i]-1].push_back(A[i+1]-1);
            b[B[i]-1].push_back(B[i+1]-1);
            x[A[i+1]-1] = 1;
            y[B[i+1]-1] = 1;
        }
        for(int i = 0;i<n;i++)
        {
            // cout<<i+1<<": ";
            // for(int j = 0;j<a[i].size();j++)
            // {
            //     cout<<a[i][j]+1<<" ";
            // }
            // cout<<endl;
            if(x[i] == 0)
                root = i;
            if(y[i] == 0)
                root2 = i;
        }
        // for(int i = 0;i<n;i++)
        // {
        //     cout<<i+1<<": ";
        //     for(int j = 0;j<a[i].size();j++)
        //     {
        //         cout<<b[i][j]+1<<" ";
        //     }
        //     cout<<endl;
        // }
        if(root!=root2)
            return 0;
        return check(a,b,root, root2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends