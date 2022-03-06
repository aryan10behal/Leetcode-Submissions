class Solution {
public:
    void p(vector<int>& nums, vector<vector<int>> &ans, int i, int j, map<vector<int>, int> &m)
    {
        if(i==j)
        {
            if(m.find(nums) == m.end())
            {
                m[nums] = 1;
                ans.push_back(nums);    
            }
            return;
        }
        else
        {
            for(int k = i; k<=j;k++)
            {
                {
                    int x= nums[i];
                    nums[i] = nums[k];
                    nums[k] = x;
                }
                p(nums, ans, i+1, j,m);
                 {
                    int x= nums[i];
                    nums[i] = nums[k];
                    nums[k] = x;
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        map<vector<int>, int> m;
        p(nums,ans, 0, n-1, m);
        return ans;
    }
};