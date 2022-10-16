class Solution {
public:
    void construct_segment_tree(vector<int>& segtree, vector<int> &a, int n)
    {
        for (int i = 0; i < n; i++)
            segtree[n + i] = a[i];   
        for (int i = n - 1; i >= 1; i--)
            segtree[i] = max(segtree[2 * i],
                             segtree[2 * i + 1]);
    }
 
    void update(vector<int>& segtree, int pos, int value,int n)
    {
        pos += n;
        segtree[pos] = value;

        while (pos > 1) {
            pos >>= 1;
            segtree[pos] = max(segtree[2 * pos], segtree[2 * pos + 1]);
        }
    }
 
    int range_query(vector<int>& segtree, int left, int right, int n)
    {
        left += n;
        right += n;
        int mi = -1e9;

        while (left < right) {
            if (left & 1) {
                mi = max(mi, segtree[left]);
                left++;
            }
            if (right & 1) {
                right--;
                mi = max(mi, segtree[right]);
            }
            left /= 2;
            right /= 2;
        }
        return mi;
    }
    int help(vector<int>& jd, int idx, int d, int n, vector<vector<int>> &dp, vector<int> &segtree)
    {
        if(idx >= n || d <= 0)
            return 0;
        if(d == 1)
            return dp[idx][d] = range_query(segtree, idx, n, n);
        if(dp[idx][d] != 1e9)
            return dp[idx][d];
        for(int i = idx; i<=n-d;i++)
            dp[idx][d] = min(range_query(segtree, idx, i+1, n) + help(jd, i+1,d-1,n,dp,segtree), dp[idx][d]);
        return dp[idx][d];
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        vector<int> segtree(2*n);
        construct_segment_tree(segtree, jd, n);
        if(d > n)
            return -1;
        vector<vector<int>> dp(n+1, vector<int> (d+1, 1e9));
        return help(jd, 0, d, n, dp, segtree);
    }
};