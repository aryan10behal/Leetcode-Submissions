class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        int m = coins.size();
        vector<int> dp(a+1,1e9);
        dp[0] = 0;
        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-coins[j]>=0)
                {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[a]==1e9?-1:dp[a];
    }
};