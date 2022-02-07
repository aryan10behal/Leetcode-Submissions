// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void sieve(int n, vector<bool> &p)
  {
      for(int i = 2; i*i<=n;i++)
      {
          if(p[i])
          {
              for(int j = i*i; j<=n; j+=i)
                p[j] = false;
          }
      }
  }
    vector<int> primeRange(int M, int N) {
        vector<bool> primes(N+1, true);
        vector<int> ans;
        sieve(N, primes);
        primes[1] = false;
        for(int i = M;i<=N;i++)
        {
            if(primes[i])
                ans.push_back(i);
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends