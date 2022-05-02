class Solution {
public:
    bool p(int a, int b, int m, int n)
    {
        return (a>=0 && b>=0 && a<m && b<n);
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x_dir[4] = {1,0,-1, 0}, y_dir[4] = {0,-1, 0, 1};
        vector<vector<int>> fire(m, vector<int>(n, 1e9));
        queue<pair<pair<int, int>, int>> hotspot;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                    fire[i][j] = -1;
                if(grid[i][j] == 1)  
                {
                    if((i == 0 && j == 0) or (i == m-1 && j == n-1))
                        return -1;
                    fire[i][j] = 0;
                    hotspot.push({{i, j}, 0});
                }
            }
        }
        while(hotspot.size())
        {
            pair<pair<int, int>, int> val = hotspot.front();
            hotspot.pop();
            for(int i = 0;i<4;i++)
            {
                int x = val.first.first + x_dir[i];
                int y = val.first.second + y_dir[i];
                if(p(x, y, m, n) && fire[x][y] == 1e9)
                {
                    fire[x][y] = val.second+1;
                    hotspot.push({{x, y}, val.second+1});
                }
            }
        }
        // ##################
        
        queue<pair<pair<int, int>, pair<int, int>>> time;
        time.push({{0, 0},{0, fire[0][0]-1}});
        int ans = -1;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        while(time.size())
        {
            pair<pair<int, int>, pair<int, int>> val = time.front();
            time.pop();
            for(int i = 0;i<4;i++)
            {
                int x = val.first.first + x_dir[i];
                int y = val.first.second + y_dir[i];
                if(p(x, y, m, n) && vis[x][y] == 0 && fire[x][y]!=-1)
                {
                    vis[x][y] = 1;
                    if(x==m-1 && y == n-1)
                    {
                        if(fire[x][y] >= val.second.first + 1)
                        {
                            int pp = min(val.second.second, abs(fire[x][y] - val.second.first - 1));
                                // cout<<"beteee ";
                                // cout<<pp<<endl;
                                // cout<<x<<" "<<y<<" "<<fire[x][y]<<" "<<val.second.first + 1<<" "<<pp<<endl<<endl;
                                ans = max(ans, pp);
                        }
                        vis[x][y] = 0;
                    }
                    else 
                    {
                        if(fire[x][y] > val.second.first + 1)
                        {
                            int pp = min(val.second.second, abs(fire[x][y] - val.second.first - 1) - 1);
                            //cout<<x<<" "<<y<<" "<<fire[x][y]<<" "<<val.second.first + 1<<" "<<pp<<endl;
                            time.push({{x, y}, {val.second.first+1, pp}});
                        }
                    }
                }
            }
        }
       // cout<<vis[m-1][n-1]<<" "<<ans<<endl;
        if(ans == -1)
            return -1;
        //cout<<ans<<endl;
        if(ans == 0)
            return 0;
        return ans>1e7?1e9:ans;
    }
};