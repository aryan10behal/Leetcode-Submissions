class Solution {
public:
    void find(vector<vector<int>> &ans, vector<int> &v, vector<int> candidates, int c, int s, int start)
    {
        if(c==s)
        {
            ans.push_back(v);
            return;
        }
        if(c>s)
        {
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            c+=candidates[i];
            v.push_back(candidates[i]);
            find(ans, v, candidates, c, s, i);
            v.pop_back();
            c-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        find(ans, v, candidates, 0,target, 0);
        return ans;
    }
};