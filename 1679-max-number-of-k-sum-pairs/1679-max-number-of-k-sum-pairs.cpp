class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int ans= 0, i =0 , j = nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j] == k)
            {
                i++, j--;
                ans++;
            }
            else if(nums[i] + nums[j] < k)
                i++;
            else 
                j--;
        }
        return ans;
    }
};