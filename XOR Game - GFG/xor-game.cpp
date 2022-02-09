// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int xorCal(int k){
        if(k == 1)
            return 2; 
        if((k&(k+1)) != 0)
            return -1;
        int ind = -1; 
        for(int i = 31;i>=0;i--)
        {
            if((k>>i) && 1)
            {
                ind = i;
                break;
            }
        }
        return (1<<ind)-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        
        Solution ob;
        cout<<ob.xorCal(k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends