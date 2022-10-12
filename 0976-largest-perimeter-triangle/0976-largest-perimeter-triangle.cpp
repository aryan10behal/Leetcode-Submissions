class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n<=2)
            return 0;
        int a = nums[n-1], b = nums[n-2], c;
        for(int i = n-3;i>=0;i--)
        {
            c = nums[i];
            if(b + c > a)
                return a+b+c;
            a = b;
            b = c;
        }
        return 0;
    }
};