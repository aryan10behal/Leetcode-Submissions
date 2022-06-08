class Solution {
public:
    string make_LCS(string &a, string &b, vector<int> &y, vector<int> &z)
    {
        int m = a.size(), n = b.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1] == b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string x = "";
        int i = m, j = n;
        while(i!=0 and j!=0)
        {
            if(i == 0 or j == 0)
                break;
            else if(a[i-1] == b[j-1])
            {
                y.push_back(i-1);
                z.push_back(j-1);
                x += a[i-1];
                i--, j--;
            }
            else if(dp[i][j] == dp[i-1][j])
                i--;
            else
                j--;
        }
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
         reverse(z.begin(), z.end());
        return x;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<int> y, z;
        string s = make_LCS(str1, str2, y, z);
        // for(int i = 0;i<y.size();i++)
        //     cout<<y[i]<<" "<<z[i]<<endl;
        int i = 0, j = 0;
        int k = 0, l = 0;
        string ans = "";
        int m = str1.size(), n = str2.size();
        while(i<m and j<n)
        {
            while(i < y[k])
            {
                ans += str1[i++];
            }
            while(j < z[l])
            {
                ans += str2[j++];
            }
            // cout<<i<<" "<<j<<endl;
            ans += str1[i];
            i++, j++;
            k++, l++;
            if(k >= y.size())
                break;
        }
        if(i<m)
        {
            while(i<m)
                ans+=str1[i++];
        }
        if(j < n)
        {
            while(j<n)
                ans+=str2[j++];
        }
        return ans;
    }
};