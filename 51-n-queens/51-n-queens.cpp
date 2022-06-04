class Solution {
public:
    void nqueens(vector<vector<string>> &ans, vector<string> &y, int r, int n, int l, string &f, string &g, string &h)
    {
        if(r == n)
        {
            ans.push_back(y);
            return;
        }
        for(int i = l+2;i<n;i++)
        {
            if(f[i] == '.' and g[r-i + n - 1] == '.' and h[i+r] == '.')
            {
                y[r][i] = 'Q';
                f[i] = 'Q';
                g[r-i + n - 1] = 'Q';
                h[i+r] = 'Q';
               // cout<<r<<" "<<f<<endl;
                nqueens(ans, y, r+1, n, i, f, g, h);
                f[i] = '.';
                h[i+r] = '.';
                g[r-i + n - 1] = '.';
                y[r][i] = '.';
            }
        }
        for(int i = l-2;i>=0;i--)
        {
            if(f[i] == '.' and g[r-i + n - 1] == '.' and h[i+r] == '.')
            {
                y[r][i] = 'Q';
                f[i] = 'Q';
                g[r-i + n - 1] = 'Q';
                h[i+r] = 'Q';
                //cout<<r<<" "<<f<<endl;
                nqueens(ans, y, r+1, n, i, f, g, h);
                h[i+r] = '.';
                f[i] = '.';
                g[r-i + n - 1] = '.';
                y[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string f(n, '.');
        string g(2*n-1, '.');
        string h(2*n-1, '.');
        string x(n, '.');
        vector<string> y(n, x);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            y[0][i] = 'Q';
            f[i] = 'Q';
            g[-i+n-1] =  'Q';
            h[i] = 'Q';
            
            //cout<<y[0]<<endl;
            nqueens(ans,y, 1, n, i, f, g, h);
            f[i] = '.';
            g[-i+n-1] =  '.';
            y[0][i] = '.';
            h[i] = '.';
            //cout<<endl<<endl;
        }
        //cout<<ans.size()<<endl;
        return ans;
    }
};