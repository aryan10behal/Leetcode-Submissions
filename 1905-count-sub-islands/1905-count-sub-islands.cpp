class Solution {
public:
    int x_dir[4] = {0,-1,0,1};
    int y_dir[4] = {1,0,-1,0};
    void dfs(vector<vector<int>>& grid1, int x, int y, int m, int n, int count)
    {
        for(int i = 0 ;i<4;i++)
        {
            int a = x+x_dir[i];
            int b = y+y_dir[i];
            if(a>=0 && a<m && b>=0 && b<n && grid1[a][b] == 1)
            {
                grid1[a][b] = count;
                dfs(grid1, a, b, m, n, count);
            }
        }
    }
    void dfs2(vector<vector<int>>& grid2, vector<vector<int>>& grid1, int x, int y, int m, int n, int count, bool &bb)
    {
        for(int i = 0 ;i<4;i++)
        {
            int a = x+x_dir[i];
            int b = y+y_dir[i];
            if(a>=0 && a<m && b>=0 && b<n && grid2[a][b] == 1)
            {
                if(grid1[a][b] == 0)
                    bb = false;
                grid2[a][b] = count;
                dfs2(grid2, grid1, a, b, m, n, count, bb);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 2;
        map<int, int> mp;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid1[i][j] == 1)
                {
                    grid1[i][j] = count;
                    mp[count] = 1;
                    dfs(grid1, i, j, m, n, count);
                    count++;
                }
            }
        }
        int c = 0, cc = 2;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid2[i][j] == 1 && grid1[i][j]!=0)
                {
                    grid2[i][j] = cc;
                    bool ff = true;
                    dfs2(grid2, grid1, i, j, m, n, cc, ff);
                    cc++;
                    if(ff)
                        c++;
                }
            }
        }
       
        
        return c;
    }
};