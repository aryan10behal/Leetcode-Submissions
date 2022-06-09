class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int c = 1, prev = nums[0], n = nums.size(), f = 0;
        if(n == 1)
            return c;
        int i = 1;
        while(i<n and nums[i] == nums[i-1])
            i++;
        if(i == n)
            return 1;
        else
        {
            f = (nums[i] < nums[i-1]?-1:1);
            c++;
        }
        for(;i<n;i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            int x = nums[i] < nums[i-1] ? -1:1;
            if(x*f == -1)
            {
                c++;
                f = x;
            }
            prev =  nums[i];
        }
        return c;
    }
};