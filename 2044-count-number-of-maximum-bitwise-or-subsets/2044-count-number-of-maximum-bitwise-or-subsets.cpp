class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0, ans = 0;
        for(int x: nums)
            mx |= x;
        int n = nums.size();
        int combs = (1<<n);
        for(int i = 1;i<combs;i++)
        {
            int val = 0;
            for(int j = 0;j<n;j++)
            {
                if(((i>>j)&1) == 1)
                {
                    val|=nums[j];
                }
            }
            if(val == mx)
                ans++;
        }
        return ans;
    }
};