// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool p(int arr[], int N, int cap, int D)
  {
      int d = 0;
      int c = 1e9+1;
      for(int i = 0;i<N;i++)
      {
          if(arr[i] > cap)
            return false;
          else
          {
            if(c + arr[i] <= cap)
                    c += arr[i];
            else
                {
                    c = arr[i];
                    d++;
                }
          }
      }
      return d<=D?true:false;
  }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int l = 1, h = 1e9, mid, ans;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(p(arr, N, mid, D))
            {
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends