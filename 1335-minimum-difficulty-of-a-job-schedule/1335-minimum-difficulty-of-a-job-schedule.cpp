class Solution {
public:
    int help(vector<int>& jd, int idx, int d, int n, vector<vector<int>> &dp, vector<vector<int>> &segtree)
    {
        if(idx >= n || d <= 0)
            return 0;
        if(d == 1)
            return dp[idx][d] = segtree[idx][n-1];
        if(dp[idx][d] != 1e9)
            return dp[idx][d];
        for(int i = idx; i<=n-d;i++)
        {
            dp[idx][d] = min(segtree[idx][i] + help(jd, i+1,d-1,n,dp,segtree), dp[idx][d]);
        }
        return dp[idx][d];
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        vector<vector<int>> segtree(n, vector<int>(n));
        for(int i = 0;i<n;i++)
        {
            int mn = -1;
            for(int j = i;j<n;j++)
            {
                mn = max(mn, jd[j]);
                segtree[i][j] = mn;
            }
        }
        if(d > n)
            return -1;
        vector<vector<int>> dp(n+1, vector<int> (d+1, 1e9));
        return help(jd, 0, d, n, dp, segtree);
    }
};