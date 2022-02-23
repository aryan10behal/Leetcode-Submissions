// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

bool p(int a[], int n, int k, int mid)
{
    int count = 0;
    int i = 0, j = 1;
    while(j<n)
    {
        if(abs(a[j] - a[i]) <= mid)
        {
            count+= j-i;
            j++;
        }
        else
            i++;
    }
    //cout<<count<<" "<<k<<endl;
    if(count<k)
        return true;
    return false;
}
int kthDiff(int a[], int n, int k) {
    sort(a, a + n);
    int low = 0, high = a[n - 1] - a[0], ans = 0;
    while (low < high) {
        int mid = (low + high) / 2;
        //cout << low << " " << mid << " " << high << endl;
        if (p(a, n, k, mid))
            low = mid + 1;
        else
            high = mid;

    }
    return low;
}