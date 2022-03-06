class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> ans(r+1, 0);
        for(int i=0;i<=r;i++)
        {
            int prev = 1;
            for(int j = 0;j<=i;j++)
            {
                if(j == 0 or j == i)
                    ans[j] = 1;
                else
                {
                    int x = ans[j];
                    ans[j] = prev + ans[j];
                    prev = x;
                }
            }
        }
        return ans;
    }
};