// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void rev(vector<int> &arr, int l, int r)
    {
        while(l<r)
        {
            int t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            l++, r--;
        }
    }
    vector<int> nextPermutation(int N, vector<int> arr){
        int ind = N;
        for(int i = N-1;i>=1;i--)
        {
            if(arr[i]>arr[i-1])
                {
                    ind = i-1;
                    break;
                }
        }
        if(ind == N)
        {
            rev(arr, 0, N-1);
        }
        else
        {
            //cout<<ind<<endl;
            int ind2 = -1;
            for(int i = ind+1; i<N;i++)
            {
                if(arr[i] > arr[ind])
                    ind2 = i;
            }
            int t = arr[ind2];
            arr[ind2] = arr[ind];
            arr[ind] = t;
            // for(int i = 0;i<N;i++)
            // {
            //     cout<<arr[i]<<" ";
            // }
            // cout<<endl;
            // cout<<ind2<<endl;
            rev(arr, ind+1, N-1);
        }
        return arr;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends