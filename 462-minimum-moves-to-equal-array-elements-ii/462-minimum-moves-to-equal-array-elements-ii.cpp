class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> val(n, 0);
        long long ans = 1e18, sum = 0;
        for(long long i = 1;i<n;i++)
        {
            sum+= i*(nums[i] - nums[i-1]);
            val[i] += sum;
        }
        ans = min(val[n-1], ans);
        sum = 0;
        for(long long i = n-2;i>=0;i--)
        {
            sum += (n-i-1)*(nums[i+1] - nums[i]);
            val[i] += sum;
            ans = min(val[i], ans);
        }
        return ans;
    }
};