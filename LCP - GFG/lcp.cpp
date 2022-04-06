// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        int m = ar[0].size();
        string k = ar[0];
        for(int i = 1;i<n;i++)
        {
            int j = min(m, (int)ar[i].size());
            int l = 0, v = 0;
            while(l<j and k[l] == ar[i][l])
                l++;
            m = min(l, m);
            k = k.substr(0, m);
            if(k == "")
                return "-1";
        }
        return k;
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends