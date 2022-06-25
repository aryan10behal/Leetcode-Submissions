class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int x = 0, n = nums.size();
        vector<int> xx = nums;
        for(int i = 0;i<n-1;i++)
        {
            if(nums[i] > nums[i+1])
            {
                xx[i] = xx[i+1];
                nums[i+1] = nums[i];
                break;
            }
        }
        int p = 0, q = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(nums[i] > nums[i+1])
               { 
                 p|=1;
               }
        }
        for(int i = 0;i<n-1;i++)
        {
            if(xx[i] > xx[i+1])
               { 
                 q|=1;
               }
        }
        return (p&q==1)?false:true;
    }
};