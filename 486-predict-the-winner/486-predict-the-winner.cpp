class Solution {
public:
    int dfs(vector<int>& nums, int i, int j, int c)
     {
        if(i==j)
        {
            if(c == 0)
                return nums[i];
            return -nums[i];
        }
        if(c == 0)
        {
            int a = nums[i] + dfs(nums, i+1, j, c^1);
            int b = nums[j] + dfs(nums, i, j-1, c^1);
            return max(a, b);
        }
        else
        {
            int a = -1*nums[i] + dfs(nums, i+1, j, c^1);
            int b = -1*nums[j] + dfs(nums, i, j-1, c^1);
            return min(a, b);
        }
        return -1;
     }
    bool PredictTheWinner(vector<int>& nums) {
        int c = 0, i = 0, j = nums.size()-1;
        int l = dfs(nums, i, j, 0); 
        //cout<<l<<endl;
        return l>=0?true:false;
    }
};