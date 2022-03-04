// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int n, vector<int> a,int x)
    {
       int prefix=0,ans=n;
        for(int i=30;i>=0;i--){
            if(((x>>i)&1)!=0){
                prefix^=(1l<<i);
                continue;
            }
            int ct=0;
            long p=prefix^(1l<<i);
            for(int j=0;j<n;j++){
                if((a[j]&p)==p)
                    ct++;
            }
            ans=min(ans,n-ct);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends