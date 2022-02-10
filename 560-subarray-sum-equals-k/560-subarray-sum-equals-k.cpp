class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int s = 0;
        m[s] = 1;
          int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            ans+=m[s-k];
            m[s]++;
        }
        return ans;
            
    }
};