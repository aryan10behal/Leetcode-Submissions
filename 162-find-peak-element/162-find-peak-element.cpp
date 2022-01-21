class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            //cout<<l<<" "<<mid<<h<<endl;
            if((mid == 0 || nums[mid-1] <nums[mid]) && (mid == n-1 || nums[mid+1]< nums[mid]))
                return mid;
            else if(mid>0 && nums[mid-1] > nums[mid])
                h = mid - 1;
            else
                 l = mid + 1;
       }
        return -1;
    }
};