// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    int dp[n][m];
	    int mod = 1e9+7;
	    memset(dp, 0, sizeof(dp));
	    dp[0][0] = 1;
	    for(vector<int> k: blocked_cells)
	        dp[k[0]-1][k[1]-1] = -1;
	    for(int i = 1;i<n;i++)
	    {
	        if(dp[i][0]!=-1)
	            dp[i][0] = dp[i-1][0]%mod;
	    }
	    for(int i = 1;i<m;i++)
	    {
	        if(dp[0][i]!=-1)
	            dp[0][i] = dp[0][i-1]%mod;
	    }
	    for(int i = 1;i<n;i++)
	    {
	        for(int j = 1;j<m;j++)
	        {
	            if(dp[i][j]!=-1)
	                dp[i][j] = ((dp[i-1][j] == -1?0:dp[i-1][j])%mod + (dp[i][j-1] == -1?0:dp[i][j-1])%mod)%mod;
	            if(dp[i][j] == 0)
	                dp[i][j] = -1;
	        }
	    }
	    return dp[n-1][m-1] == -1?0:dp[n-1][m-1]%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends