class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int p = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(ans == nums[i])
                p++;
            else
            {
                p--;
                if(p < 0)
                {
                    p = 1;
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};