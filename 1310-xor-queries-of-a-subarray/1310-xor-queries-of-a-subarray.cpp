class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n);
        int x = 0;
        for(int i=0;i<n;i++)
        {
            x^= arr[i];
            pre[i] = x;
        }
        vector<int> ans;
        for(vector<int> b: queries)
        {
            if(b[0] == 0)
            {
                ans.push_back(pre[b[1]]);
            }
            else
            {
                ans.push_back(pre[b[1]]^pre[b[0] - 1]);
            }
        }
        return ans;
    }
};