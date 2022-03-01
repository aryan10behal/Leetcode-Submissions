// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
       long long n = S.size();
       vector<int> a(26,0);
       for(int i=0;i<n;i++)
           a[S[i]-'a']++;
       long long ans = 0;
       for (int i=0;i<n;i++)
           ans+=n-a[S[i]-'a'];
       ans /= 2;
       for (int i=0;i<26;i++) {
           if (a[i]>=2) {
               ans++;
               break;
           }
       }
       return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends