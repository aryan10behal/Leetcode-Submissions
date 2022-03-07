class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int mx = nums[k], mn = nums[k];
        while(i>=1 && j<n-1)
        {
            if(nums[i-1] < nums[j+1])
            {
                j++;
                mn = min(mn, nums[j]);
                mx = max(mx, mn*(j-i+1));
            }
            else
            {
                i--;
                mn = min(mn, nums[i]);
                mx = max(mx, mn*(j-i+1));
            }
        }
        while(j<n - 1)
        {
            j++;
            mn = min(mn, nums[j]);
            //cout<<i<<"$ "<<j<<" "<<mn<<endl;
            mx = max(mx, mn*(j-i+1));
        }
        while(i>=1)
        {
            i--;
            mn = min(mn, nums[i]);
            //cout<<i<<" $"<<j<<" "<<mn<<endl;
            mx = max(mx, mn*(j-i+1));
        }
        return mx;
    }
};