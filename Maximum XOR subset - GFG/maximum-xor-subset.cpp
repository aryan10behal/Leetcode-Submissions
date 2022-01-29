// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int maxXor(int arr[], int n)
	{
		// Your code goes here
		int ind = 0;
		for(int i = 31;i>=0;i--)
		{
		    int mx = -1;
		    int m = 0;
		    for(int j = ind; j < n;j++)
		    {
		        if(((1<<i)&arr[j]))
		            {
		                if(arr[j] > m)
		                    {
		                        m = arr[j];
		                        mx = j;
		                    }
		            }
		    }
	        //cout<<i<<" "<<mx<<endl;
		    if(mx == -1)
		        continue;
		    int t = arr[mx];
		    arr[mx] = arr[ind];
		    arr[ind] = t;
		    for(int j = 0; j < n;j++)
		    {
		        if(j == ind)
		            continue;
		        if(((1<<i)&arr[j]))
		            {
		               arr[j]^= t;
		            }
		    }
		    ind++;
		}
        int ans = 0;
        for(int i = 0;i<n;i++)
            ans^=arr[i];
        return ans;
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	   

	    Solution ob;
	    cout << ob.maxXor(a, n) << "\n";
   
    }
    return 0;
}
  // } Driver Code Ends