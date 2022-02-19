// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
int x_dir[8] = {1,0,-1,0,1,1,-1,-1};
int y_dir[8] = {0,1,0,-1,1,-1,1,-1};
bool p(int a, int b, int c, int d)
{
    if(a>=0 && a<c && b>=0 && b<d)
        return true;
    return false;
}
void dfs(int x, int y,vector<vector<char>>& M, int n, int m)
{
    for(int i=0;i<8;i++)
    {
        int xx = x+x_dir[i];
        int yy = y+y_dir[i];
        if(p(xx,yy,n,m) && M[xx][yy] == '1')
        {
            M[xx][yy]='0';
            dfs(xx,yy,M,n,m);
        }
    }
}
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& M) {
        int ans = 0;
        int n = M.size(), m = M[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(M[i][j]=='1')
                {
                    ans++;
                    M[i][j] = '0';
                    dfs(i, j, M, n, m);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends