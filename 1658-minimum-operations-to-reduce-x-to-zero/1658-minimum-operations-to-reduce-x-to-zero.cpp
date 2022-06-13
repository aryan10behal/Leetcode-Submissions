class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        int n = nums.size();
        for(int y: nums)
            sum+=y;
        if(sum == x)
            return n;
        x = sum - x;
        // basically now I need to find the largest subarray with sum = x;
        for(int i = 1;i<n;i++)
            nums[i] += nums[i-1];
        int ans  = 1e9;
        for(int i = 0;i<n;i++)
        {
            int l = i, h = n-1, m, a = -1;
            while(l<=h)
            {
                m = (h-l)/2 + l;
                long long val = nums[m] - (i == 0? 0:nums[i-1]);
                if(val == x)
                {
                    a = m - i + 1;
                    break;
                }
                else if(val < x)
                    l = m+1;
                else
                    h = m-1;
            }
            if(a != -1)
                ans = min(ans, n-a);
        }
        // cout<<x<<endl;
        return ans == 1e9? -1: ans;
    }
};