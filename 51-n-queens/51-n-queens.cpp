class Solution {
public:
    void nqueens(vector<vector<string>> &ans, vector<string> &y, int r, int n, int l, string &columns, string &diag1, string &diag2)
    {
        if(r == n)
        {
            ans.push_back(y);
            return;
        }
        for(int i = l+2;i<n;i++)
        {
            if(columns[i] == '.' and diag1[r-i + n - 1] == '.' and diag2[i+r] == '.')
            {
                y[r][i] = 'Q';
                columns[i] = 'Q';
                diag1[r-i + n - 1] = 'Q';
                diag2[i+r] = 'Q';
               // cout<<r<<" "<<f<<endl;
                nqueens(ans, y, r+1, n, i, columns, diag1, diag2);
                columns[i] = '.';
                diag2[i+r] = '.';
                diag1[r-i + n - 1] = '.';
                y[r][i] = '.';
            }
        }
        for(int i = l-2;i>=0;i--)
        {
            if(columns[i] == '.' and diag1[r-i + n - 1] == '.' and diag2[i+r] == '.')
            {
                y[r][i] = 'Q';
                columns[i] = 'Q';
                diag1[r-i + n - 1] = 'Q';
                diag2[i+r] = 'Q';
                //cout<<r<<" "<<f<<endl;
                nqueens(ans, y, r+1, n, i, columns, diag1, diag2);
                diag2[i+r] = '.';
                columns[i] = '.';
                diag1[r-i + n - 1] = '.';
                y[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string columns(n, '.');
        string diag1(2*n-1, '.');
        string diag2(2*n-1, '.');
        vector<string> y(n, string(n, '.'));
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            y[0][i] = 'Q';
            columns[i] = 'Q';
            diag1[-i+n-1] =  'Q';
            diag2[i] = 'Q';
            nqueens(ans,y, 1, n, i, columns, diag1, diag2);
            columns[i] = '.';
            diag1[-i+n-1] =  '.';
            y[0][i] = '.';
            diag2[i] = '.';
        }
        //cout<<ans.size()<<endl;
        return ans;
    }
};