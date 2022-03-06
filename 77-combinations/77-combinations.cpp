class Solution {
public:
    int find_bits(int x)
    {
        int c = 0;
        while(x)
        {
            x&=(x-1);
            c++;
        }
        return c;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int i = 0;i<(1<<n);i++)
        {
            if(find_bits(i) != k)
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