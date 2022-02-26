class Solution {
public:
    int find(vector<int>& coins, vector<vector<int>>& dp, int amount, int ind)
    {   
        if(amount < 0 or ind>=coins.size())
            return 0;
        if(amount == 0)
            return 1;
        if(dp[amount][ind]!=1e9)
            return dp[amount][ind];
        dp[amount][ind] = 0;
        dp[amount][ind] += (find(coins, dp, amount-coins[ind],ind) + find(coins, dp, amount,ind+1));
        return dp[amount][ind];
    }
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int> (n, 1e9));
        sort(coins.begin(), coins.end());
        find(coins, dp, amount, 0);
        return dp[amount][0] == 1e9?0:dp[amount][0];
    }
};