// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int arr[], int n)
{
    vector<int> x(arr, arr + n);
    sort(x.begin(), x.end());
    map<int, int> m;
    for(int i=0;i<n-1;i++)
        m[x[i]] = x[i+1];
    m[x[n-1]] = -10000000;
    for(int i=0;i<n;i++)
    {
        arr[i] = m[arr[i]];
    }
    return arr;
}
