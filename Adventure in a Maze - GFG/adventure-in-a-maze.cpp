// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int mod = 1e9 + 7;
    vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {0, 0}));
    dp[0][0] = {1,matrix[0][0]};
    for(int i = 1;i<n;i++)
    {
        if((matrix[0][i-1]&1)== 1 and dp[0][i-1].first != 0)
        {
            dp[0][i] = {dp[0][i-1].first%mod, (dp[0][i-1].second + matrix[0][i])%mod}; 
        }
    }
    for(int i = 1;i<m;i++)
    {
        if((matrix[i-1][0] == 2 or matrix[i-1][0] == 3) and dp[i-1][0].first != 0)
        {
            dp[i][0] = {dp[i-1][0].first%mod, (dp[i-1][0].second + matrix[i][0])%mod}; 
        }
    }
    for(int i =1;i<m;i++)
    {
        for(int j = 1;j<n;j++)
        {
            int a = 0, b = 0;
            if((matrix[i][j-1]&1) == 1 and dp[i][j-1].first != 0)
            {
                dp[i][j].first += dp[i][j-1].first;
                dp[i][j].first%=mod;
                a = dp[i][j-1].second%mod;
            }
            if((matrix[i-1][j] == 2 or matrix[i-1][j] == 3) and dp[i-1][j].first != 0)
            {
                dp[i][j].first += dp[i-1][j].first;
                dp[i][j].first%=mod;
                b = dp[i-1][j].second%mod;
            }
            if(a+b > 0)
            {
                dp[i][j].second = (max(a, b) + matrix[i][j])%mod;
            }
        }
    }
    vector<int> ans = {dp[m-1][n-1].first, dp[m-1][n-1].second};
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends