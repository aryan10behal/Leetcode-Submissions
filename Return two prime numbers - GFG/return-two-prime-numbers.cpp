// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void sieve(int N, vector<bool> &prime)
    {
        for(int i = 2;i<=N;i++)
        {
            if(prime[i])
            {
                for(int j = i*2; j<=N ; j+=i)
                {
                    prime[j] = false;
                }
            }
        }
    }
    vector<int> primeDivision(int N){
        vector<bool> prime(N+1, true);
        sieve(N, prime);
        vector<int> x(2);
        for(int i = 2; i<=N; i++)
        {
            if(prime[i] == 1 && prime[N-i] == 1)
                {
                    x[0] = i;
                    x[1] = N - i;
                    break;
                }
        }
        return x;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends