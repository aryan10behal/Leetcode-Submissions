// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int set(int a)
    {
        int x = 0;
        for(int i = 31;i>=0;i--)
        {
            if((a>>i)&1 == 1)
                x++;
        }
        return x;
    }
    static bool comp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>> &b)
    {
        if(a.second.second > b.second.second)
            return true;
        else if(a.second.second == b.second.second)
        {
            if(a.second.first < b.second.first)
                return true;
        }
        return false;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int, pair<int, int>>> p(n);
        for(int i = 0;i<n;i++)
        {
            p[i] = {arr[i], {i, set(arr[i])}};
        }
        sort(p.begin(), p.end(), comp);
        for(int i = 0;i<n;i++)
            arr[i] = p[i].first;
        // Your code goes here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends