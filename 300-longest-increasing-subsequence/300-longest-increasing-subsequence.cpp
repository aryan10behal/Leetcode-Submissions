class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += 1;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};