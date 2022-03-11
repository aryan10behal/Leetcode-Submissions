// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long int divide(long long arr[], long long l, long long h)
    {
        if(l>=h)
            return 0;
        if(l+1 == h)
        {
            if(arr[l] > arr[h])
                {
                    long long x = arr[l];
                    arr[l] = arr[h];
                    arr[h] = x;
                    return 1;
                }
            return 0;
        }
        long long mid = (l+h)/2;
        long long int a = divide(arr, l, mid-1);
        a+= divide(arr, mid, h);
        long long int f[h-l+1];
        long long k = 0, i = l, j = mid;
        while(i<mid && j<=h)
        {
            if(arr[i] <= arr[j])
                f[k++] = arr[i++];
            else
            {
                a += (mid - i);
                f[k++] = arr[j++];
            }
        }
        while(i<mid)
            f[k++] = arr[i++];
        while(j<=h)
            f[k++] = arr[j++];
        k = 0;
        while(l<=h)
            arr[l++] = f[k++];
        return a;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return divide(arr, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends