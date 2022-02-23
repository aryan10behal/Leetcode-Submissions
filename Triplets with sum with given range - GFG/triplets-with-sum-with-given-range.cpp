// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int triplet_less_than_k(int A[], int N, int L)
    {
        int count = 0;
        for(int i=0;i<N-2;i++)
        {
            int j = i+1, k = N-1;
            int t = L - A[i];
            while(j < k)
            {
                if(A[k] + A[j] <= t)
                    {
                        count+= k - j;
                        j++;
                    }
                else
                    k--;
            }
        }
        return count;
    }
    int countTriplets(int A[], int N, int L, int R) {
        sort(A, A + N);
        return triplet_less_than_k(A, N, R) - triplet_less_than_k(A, N, L-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends