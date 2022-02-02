class Solution {
public:
    bool p(vector<int>& nums, int target, int mid)
    {
        int i = 0, sum = 0;
        int n = nums.size();
        while(i<n)
        {
            if(i<mid-1)
            {
                sum+=nums[i];
                i++;
            }
            else
            {
                sum+=nums[i];
                if(sum >= target)
                    return true;
                i++;
                sum-=nums[i - mid];
            }
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 1, h = nums.size(), mid, ans = 0;
        while(l<=h)
        {
            mid = (l + h)/2;
            //cout<<l<<" "<<h<<" "<<mid<<endl;
            if(p(nums, target, mid))
            {
                //cout<<"YO\n";
                ans = mid;
                h  = mid - 1;
            }
            else
                l = mid+1;
        }
        return ans;
        
    }
};