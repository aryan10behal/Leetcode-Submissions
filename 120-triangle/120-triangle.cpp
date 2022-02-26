class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int> (n+1,1e9));
        int ans = 1e9;
        for(int i =0 ;i<m;i++)
        {
            for(int j = 0;j<triangle[i].size();j++)
            {
                if(i == 0)
                {
                    dp[i][j] = triangle[i][j]; 
                }
                else
                {
                    dp[i][j] = min(j>0?dp[i-1][j-1]:ans, dp[i-1][j]) + triangle[i][j];
                }
                if(i == m-1)
                {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};