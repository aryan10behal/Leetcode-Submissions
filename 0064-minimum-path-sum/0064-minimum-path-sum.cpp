class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> x(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    x[i][j] = grid[0][0];
                else if(i==0)
                {
                    x[i][j] = x[i][j-1] + grid[i][j];
                }
                else if(j==0)
                {
                    x[i][j] = x[i-1][j] + grid[i][j];
                }
                else
                {
                    x[i][j] = grid[i][j] + min(x[i-1][j],x[i][j-1]);
                }
            }
        }
        return x[m-1][n-1];
    }
};