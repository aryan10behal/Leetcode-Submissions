class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(3, vector<int>(n+1));
        dp[0][0] = 0;
        dp[1][0] = -1e9;
        dp[2][0] = -1e9;
        for(int j=1;j<=nums.size();j++)
            {
            for(int i = 0; i<3;i++)
            {
                //cout<<(i + nums[j-1]%3)%3<<" ";
                int x = dp[(i + nums[j-1]%3)%3][j-1] + nums[j-1];
                int y = dp[i][j-1];
               // int x = 0, y = 0;
                dp[i][j] = max(x, y);
            }
            //cout<<endl;
        }
        // for(int i = 0;i<=n;i++)
        //     cout<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<endl;
        return dp[0][n];
    } 
};