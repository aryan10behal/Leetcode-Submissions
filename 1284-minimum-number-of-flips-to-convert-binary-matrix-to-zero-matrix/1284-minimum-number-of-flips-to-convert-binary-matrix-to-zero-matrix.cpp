class Solution {
public:
    int x0[4] = {1, 0, -1, 0};
    int y0[4] = {0, 1, 0, -1};
    bool p(int a, int b, int m, int n)
    {
        if(a>=0 && b>=0 && a<m && b<n)
            return true;
        return false;
    }
    void change(int x, int y, int m, int n, vector<vector<int>>& mat)
    {
        mat[x][y]^=1;
        for(int i = 0;i<4;i++)
        {
            int a = x0[i] + x;
            int b = y0[i] + y;
            if(p(a,b,m,n))
            {
                mat[a][b]^=1;
            }
        }
    }
    void dfs(int x, int y, vector<vector<int>>& mat, vector<vector<int>>& vis, int m, int n, int turns, int& ans)
    {
        int f = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j] == 1)
                {
                    f = 1;
                    break;
                }
            }
        }
        if(f == 0)
        {
            ans = min(ans, turns);
            return;
        }
        vis[x][y] = 1;
        change(x, y, m, n, mat);
        f = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j] == 1)
                {
                    f = 1;
                    break;
                }
            }
        }
        if(f == 0)
        {
            change(x, y, m, n, mat);
            ans = min(ans, turns + 1);
            return;
        }
        for(int i = 0;i<4;i++)
        {
            int a = x0[i] + x;
            int b = y0[i] + y;
            if(p(a,b,m,n) && vis[a][b] == 0)
            {
                vis[a][b] = 1;
                dfs(a, b, mat, vis, m, n, turns + 1, ans);
                vis[a][b] = 0;
            }
        }
        change(x, y, m, n, mat);
        for(int i = 0;i<4;i++)
        {
            int a = x0[i] + x;
            int b = y0[i] + y;
            if(p(a,b,m,n) && vis[a][b] == 0)
            {
                vis[a][b] = 1;
                dfs(a, b, mat, vis, m, n, turns, ans);
                vis[a][b] = 0;
            }
        }
        vis[x][y] = 0;
    }
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 1e9, f = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        dfs(0, 0, mat, vis, m, n, 0, ans);
        return ans==1e9?-1:ans;
    }
};