class Solution {
public:
    bool p(int a, int b, int m, int n)
    {
        return a>=0 and a<m and b>=0 and b<n;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int dirx[8] = {0,-1,0,1,-1,-1,1,1};
        int diry[8] = {1,0,-1,0,1,-1,1,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c = 0;
                for(int k = 0;k<8;k++)
                {
                    int x = i + dirx[k];
                    int y = j + diry[k];
                    if(p(x, y, m, n) and abs(board[x][y]) == 1)
                        c++;
                }
                cout<<c<<" ";
                if(c < 2 or c>3)
                    board[i][j] *=-1;
                else if(c==3)
                {
                    if(board[i][j] == 0)
                        board[i][j] = 2;
                }
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
                if(board[i][j] == 2)
                    board[i][j] = 1;
                if(board[i][j] == -1)
                    board[i][j] = 0;
            }
            cout<<endl;
        }
    }
};