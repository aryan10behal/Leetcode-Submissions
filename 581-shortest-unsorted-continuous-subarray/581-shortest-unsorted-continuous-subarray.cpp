class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> val = nums;
        sort(val.begin(), val.end());
        int n = nums.size();
        int i = 0, j = n-1;
        while(i<=j && nums[i] == val[i])
            i++;
        while(j>=i && nums[j] == val[j])
            j--;
        return j-i+1;
    }
};