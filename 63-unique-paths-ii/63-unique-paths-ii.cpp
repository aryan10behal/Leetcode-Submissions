class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0])
            return 0;
        vector<vector<int>> v(m,vector<int> (n,0));
        v[0][0] = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j])
                    v[i][j] = 0;
                else
                {
                    if(i==0 && j==0)
                        continue;
                    if(i==0)
                        v[i][j] = v[i][j-1];
                    else if(j==0)
                        v[i][j] = v[i-1][j];
                    else
                    {
                        v[i][j] = v[i-1][j] + v[i][j-1];
                    }    
                }
            }
        }
        return v[m-1][n-1];
    }
};