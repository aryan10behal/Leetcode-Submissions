// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long neg = arr[0], pos = arr[0];
	    long long ans = arr[0];
	    for(int i = 1;i<n;i++)
	    {
	        if(arr[i] < 0)
	            {
	                long long int a = neg;
	                neg = pos;
	                pos = a;
	            }
	       pos = max((long long)arr[i], arr[i]*pos);
	       neg = min((long long)arr[i], arr[i]*neg);
	       ans = max(pos, ans);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends