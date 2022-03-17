// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    const int mod = 1e9+7;
    using ll = long long;
    int max_K;
    int kvowelwords(int N, int K) {
        int cnt = 0;
        max_K = K;
        vector<vector<ll>> dp(N+1,vector<ll> (K+1,-1));
        
        for(int i=0; i<=N; i++){
            for(int j=0; j<=K; j++){
                if(i == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(j>0){
                    dp[i][j] = (5*dp[i-1][j-1]%mod+21*dp[i-1][K]%mod)%mod;
                }
                else{
                    dp[i][j] = 21*dp[i-1][K]%mod;
                }
            }
        }
        return dp[N][K];
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends