class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int i = 0;i<(1<<n);i++)
        {
            if(__builtin_popcount(i) != k)
                continue;
            vector<int> x;
            for(int j = 0;j<n;j++)
            {
                if((i>>j)&1)
                    x.push_back(j+1);
            }
            if(x.size() == k)
                ans.push_back(x);
        }
        return ans;
    }
};