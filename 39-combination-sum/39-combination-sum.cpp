class Solution {
public:
    vector<vector<int>> x;
    void isSubsetSum(vector<int> &c, int n, int sum, vector<int> &cur_vec)
    {
        if(sum == 0)
        {
            x.push_back(cur_vec);  
            return;
        }
        if(sum < 0)
            return;
        if (n == -1)
            return;
        cur_vec.push_back(c[n]);
        isSubsetSum(c, n, sum-c[n], cur_vec);
        cur_vec.pop_back();
        isSubsetSum(c, n-1, sum, cur_vec);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> cur_vec;
        int n = candidates.size() - 1;
        isSubsetSum(candidates, n, target, cur_vec);
        return x;
    }
};