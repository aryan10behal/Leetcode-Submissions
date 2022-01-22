class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int window = 0;window<n;window++)
        {
            for(int l = 1;l<=n;l++)
            {
                int r = l+window;
                if(r>n)
                    break;
                if(l == r)
                    dp[l][r]=1;
                else
                {
                    if(s[l-1] == s[r-1])
                        dp[l][r] = dp[l+1][r-1] + 2;
                    else
                        dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
                }
            }
        }
        return dp[1][n];
    }
};