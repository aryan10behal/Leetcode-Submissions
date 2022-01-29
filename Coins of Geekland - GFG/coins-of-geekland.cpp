// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int k){
        // Your code goes here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> x(m, vector<int>(n));
        x[0][0] = mat[0][0];
        for(int i = 1;i<m;i++)
        {
            x[i][0] = x[i-1][0] + mat[i][0];
        }
        for(int i = 1; i < n;i++)
        {
            x[0][i] = x[0][i-1] + mat[0][i];
        }
        for(int i = 1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                x[i][j] = x[i][j-1] + x[i-1][j] - x[i-1][j-1] + mat[i][j];
            }
        }
        int l = x[k-1][k-1];
        for(int i = k;i<m;i++)
        {
            l = max(x[i][k-1] - x[i-k][k-1], l);
        }
        for(int i = k;i<n;i++)
        {
            l = max(x[k-1][i] - x[k-1][i-k], l);
        }
        for(int i = k;i<m;i++)
        {
            for(int j = k;j<n;j++)
            {
              l = max(l, x[i][j] - x[i-k][j] - x[i][j-k] + x[i-k][j-k]); 
            }
        }
        return l;
    }  
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends