// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int v = 0;
        int ind = -1, k= 0;
        while(N!=0)
        {
            k++;
            if(N&1 == 1)
            {
                v++;
                ind = k;
            }
            N>>=1;
        }
        return v==1?ind:-1;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends