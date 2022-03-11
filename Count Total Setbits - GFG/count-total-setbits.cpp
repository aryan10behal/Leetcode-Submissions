// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N){
        int ans = 0, c = 0, mask;
        for(int i=31;i>=0;i--)
        {
            if( ((N>>i) & 1) == 1)
            {
                int val = (i)*(1<<(i-1));
                ans += val;
                //cout<<i<<" "<<ans<<endl;
                if(c>0)
                    ans += (N^mask) + 1;
                mask |= (1<<i);
                c = 1;
            }
        }
        return ans + 1;
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
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends