class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> v(1e4+1, -1);
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, ans = 0;
        while(j<n)
        {
            if(v[nums[j]] != -1)
            {
                while(i<=v[nums[j]])
                {
                    sum -= nums[i];
                    v[nums[i]] = -1;
                    i++;
                }
            }
            sum+=nums[j];
            v[nums[j]] = j;
            ans = max(ans, sum);
            j++;
        }
        return ans;
    }
};