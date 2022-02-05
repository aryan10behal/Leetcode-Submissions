class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 1, sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int x = nums[i]%k;
            sum += x;
            sum%=k;
            if(m.find(sum)==m.end())
            {
                m[sum] = i;
            }
            else
            {
                ans = max(ans, i-m[sum]);
            }
        }
        return ans == 1? false:true;
    }
};