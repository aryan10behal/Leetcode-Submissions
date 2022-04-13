class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int u = 0, d = n-1, l = 0, r = n-1;
        vector<vector<int>> a(n, vector<int>(n));
        int k = 1;
        while(k<=n*n)
        {
            //cout<<l<<" "<<r<<endl;
            for(int i = l; i<=r;i++)
            {
                a[u][i] = k++;
            }
            u++;
            for(int i = u;i<=d;i++)
            {
                a[i][r] = k++;
            }
            r--;
            for(int i=r; i>=l; i--)
            {
                a[d][i] = k++;
            }
            d--;
            for(int i=d;i>=u;i--)
            {
                a[i][l] = k++;
            }
            l++;
        }
        return a;
    }
};