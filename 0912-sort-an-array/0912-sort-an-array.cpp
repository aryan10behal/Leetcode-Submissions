class Solution {
public:
    void mergesort(vector<int> &nums, int l, int h)
    {
        if(l>=h)
            return;
        int mid = (l+h)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, h);
        int i = l, j = mid+1, k =0;
        vector<int> b(h-l+1);
        while(i<=mid && j<=h)
        {
            if(nums[i]<nums[j])
                b[k++] = nums[i++];
            else
                b[k++] = nums[j++];
        }
        while(i<=mid)
        {
            b[k++] = nums[i++];
        }
        while(j<=h)
        {
            b[k++] = nums[j++];
        }
        k = 0;
        for(int i=l;i<=h;i++)
            nums[i] = b[k++];
    }
    vector<int> sortArray(vector<int>& nums) {
        //mergesort(nums,0,nums.size()-1);   
        sort(nums.begin(),nums.end());
        return nums;
    }
};