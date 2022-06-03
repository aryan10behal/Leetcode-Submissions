class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> rows(m , vector<int> (n, 0)), cols(m, vector<int> (n, 0));
        for(int i =0;i<m;i++)
        {
            int sum = matrix[i][0];
            rows[i][0] = sum;
            for(int j = 1;j<n;j++)
            {
                rows[i][j] = rows[i][j-1] + matrix[i][j];
            }
        }
        for(int j =0;j<n;j++)
        {
            int sum = matrix[0][j];
            cols[0][j] = sum;
            for(int i = 1;i<m;i++)
            {
                cols[i][j] = cols[i-1][j] + matrix[i][j];
            }
        }
        mat = rows;
        for(int i = 1;i<m;i++)
        {
            mat[i][0] = cols[i][0];
        }
        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                mat[i][j] = mat[i-1][j-1] + rows[i][j-1] + cols[i-1][j]  + matrix[i][j];
            }
        }
        // for(int i = 0;i<m;i++)
        // {
        //     for(int j =0;j<n;j++)
        //     {
        //         //cout<<mat[i][j]<<","<<cols[i][j]<<","<<rows[i][j]<<","<<" ";
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 and col1 == 0)
            return  mat[row2][col2];
        if(row1 == 0)
            return mat[row2][col2] - mat[row2][col1-1];
        if(col1 == 0)
            return mat[row2][col2] - mat[row1-1][col2];
        return mat[row2][col2] - mat[row2][col1-1] - mat[row1-1][col2] + mat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */