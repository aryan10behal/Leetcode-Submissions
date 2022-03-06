class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>, int> m;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0;i<(1<<n);i++)
        {
            vector<int> x;
            for(int j = 0;j<n;j++)
            {
                if(((i>>j) & 1))
                    x.push_back(nums[j]);
            }
            if(m.find(x) == m.end())
            {
                m[x] = 1;
                ans.push_back(x);
            }
        }
        return ans;
    }
};