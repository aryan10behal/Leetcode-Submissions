// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
        long long ans = 0;
        vector<unordered_map<int, long long>> mp(10);
        for(int X: numbers)
        {
            int k = X;
            int i = 0;
            while(k!=0)
            {
                i++;
                k/=10;
            }
            mp[i][X]++;
        }
        int j = 0;
        for(unordered_map<int, long long> xx: mp)
        {
            for(auto it: xx)
            {
                long long x = it.first;
                if(x > X)
                    continue;
                int i = 0;
                while(x*10 < X)
                {
                    x*=10;
                    i++;
                }
                long long k = X;
                k-=x;
                if(mp[i].find(k) != mp[i].end())
                {
                    long long val;
                    
                    if(it.first == k)
                        val = (mp[i][k]*(mp[i][k]-1));
                    else
                        val = mp[i][k]*mp[j][it.first];
                    //cout<<j<<" "<<x<<" "<<k<<" "<<val<<" "<<mp[j][it.first]<<endl;
                    ans += val;
                }
            }
            j++;
        }
        return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends