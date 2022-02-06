// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> v(1e6+1, -1);
	    vector<int> y = nums;
	    for(int i =0;i<nums.size();i++)
	        v[nums[i]] = i;
	    sort(nums.begin(), nums.end());
	    int ans =0;
	    for(int i = 0;i<nums.size();i++)
	    {
	        if(v[nums[i]] == i)
	            continue;
	        else
	        {
	            int j = v[nums[i]];
	            int l = y[i];
	            y[i] = nums[i];
	            y[j] = l;
	            v[l] = j;
	            v[nums[i]] = i;
                ans++;
	        }
	    }
	    return ans;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends