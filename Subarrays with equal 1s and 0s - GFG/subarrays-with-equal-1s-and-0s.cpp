// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        long long int ans = 0;
        unordered_map<long long int, long long int> m;
        m[0] = 1;
        int y = 0;
        for(int i = 0;i<n;i++)
        {
           if(arr[i] == 0)
                arr[i] = -1;
            y+=arr[i];
            m[y]++;
        }
        for(auto it: m)
        {
            ans = ans + it.second*(it.second-1)/2;  
        }
        return ans;
        //Your code here
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends