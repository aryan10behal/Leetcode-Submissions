class Solution {
public:
    int p(vector<int>& nums, int m)
    {
        int i = 0, j = 1, n = nums.size();
        int val = 0;
        while(j<n)
        {
            if(nums[j] - nums[i] <= m)
            {
                val += (j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return val;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, h = nums[n-1]-nums[0], ans;
        while(l<=h)
        {
            int m = (l+h)/2;
            int val = p(nums, m);
            //cout<<l<<" "<<m<<" "<<h<<" "<<val<<endl;
            if(val >= k)
            {
                ans = m;
                h = m-1;
            }

            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};