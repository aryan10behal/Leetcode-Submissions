class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        for(int x: nums)
        {
            if((x&1) == 1)
                odd.push_back(x);
        }
        int k = 0, i = 0;
        for(i = 0;i<nums.size();i++)
        {
            if(nums[i]%2 == 0)
            {
                nums[k++] = nums[i];
            }
        }
        i = 0;
        for(;k<nums.size();k++)
        {
            nums[k] = odd[i++];
        }
        return nums;
    }
};