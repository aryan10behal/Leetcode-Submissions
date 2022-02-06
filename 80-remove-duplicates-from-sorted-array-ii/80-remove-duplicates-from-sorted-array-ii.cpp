class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = -1e5, t = 0, k = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(x!=nums[i])
            {
                t = 1;
                x = nums[i];
                nums[k++] = nums[i];
            }
            else 
            {
                if(t == 1)
                {
                    t++;
                     nums[k++] = nums[i];
                }
                else
                {
                    continue;
                }
            }
        }
        return k;
    }
};