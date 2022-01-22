class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n+1];
        dp[0] = false;
        for(int i = 1;i<=n;i++)
        {
            dp[i] = false;
            for(int j = 1; j*j<=i;j++)
            {
                if(dp[i - j*j] == false)
                {
                    dp[i] = true;
                    break;
                }
            }
            //cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};