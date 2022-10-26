class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 1, sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum = (sum + nums[i])%k;
            if(m.find(sum)==m.end())
                m[sum] = i;
            else
            {
                ans = max(ans, i-m[sum]);
                if(ans>=2)
                    return true;
            }
        }
        return false;
    }
};