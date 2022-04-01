// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        if(n == 1 or n==2)
        {
            vector<int> x(1, -1);
            return x;
        }
        vector<int> bigger(n, -1);
        bigger[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--)
            bigger[i] = max(arr[i], bigger[i+1]);
        long long ans = -1;
        vector<int> kk(3, -1);
        set<int> s;
        s.insert(arr[0]);
        for(int i = 1;i<n-1;i++)
        {
            auto it = s.lower_bound(arr[i]);
            it--;
            if(bigger[i] == arr[i])
            {
                 s.insert(arr[i]);
                 continue;
            }
            //cout<<arr[i]<<" "<<*it<<" "<<*s.begin()<<endl;
            long long val = (*it)*1LL*arr[i]*bigger[i];
            if(val > ans)
            {
                ans = val;
                kk = {*it, arr[i], bigger[i]};
            }
            s.insert(arr[i]);
        }
        return kk;
    } 
};
// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends