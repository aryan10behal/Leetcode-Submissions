// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> q) {
        vector<vector<int>> ans(n, vector<int> (n+1, 0));
        for(int i=0;i<q.size();i++)
        {
            int t = q[i][0], l = q[i][1], b = q[i][2], r = q[i][3];
            for(int j = t; j<=b; j++)
            {
                ans[j][l]++;
                ans[j][r+1]--;
            }
        }
        vector<vector<int>> f_ans(n,vector<int> (n, 0));
        for(int i = 0 ;i<n;i++)
        {
            for(int j = 1;j<n;j++)
            {
                ans[i][j] += ans[i][j-1];
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                f_ans[i][j] = ans[i][j];
            }
        }
        return f_ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends