class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        int diff = nums[1] - nums[0];
        int ans = 0;
        int b = 0;
        for(int i = 2; i<n; i++)
        {
            //cout<<i<<" "<<diff<<endl;
            if(diff == nums[i] - nums[i-1])
            {
                //cout<<(i-b-1)<<endl;
                ans += (i-b-1); 
            }
            else
            {
                diff = nums[i] - nums[i-1];
                b = i -1;
            }
        }
        return ans;
    }
};