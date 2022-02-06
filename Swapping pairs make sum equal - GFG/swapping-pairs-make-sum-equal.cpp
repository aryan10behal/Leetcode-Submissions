// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int s = 0, s2 = 0;
        map<int, int> mm;
        for(int i= 0;i<n;i++)
         {
            mm[A[i]] = 1;
            s += A[i];
	    }   
        for(int i = 0;i<m;i++)
            s2 += B[i];
        if(abs(s2-s)%2 == 1)
            return -1;
        int diff = (s2 - s)/2;
        for(int i = 0;i<m;i++)
        {
            if(mm.find(B[i]-diff) != mm.end())
            {
                //cout<<B[i]<<" "<<B[i]-diff<<endl;
                return 1;
            }
        }
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends