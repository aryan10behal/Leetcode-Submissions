// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n)
    {
        vector<int> bits(32, 0);
        int i = 0;
        while(x!=0)
        {
            bits[i++] = x%2;
            x>>=1;
        }
        for(int i=p1, j = p2; i<p1+n; i++, j++)
        {
            int k = bits[i];
            bits[i] = bits[j];
            bits[j] = k;
        }
        x = 0;
        for(int i = 31;i>=0;i--)
            x = x*2 + bits[i];
        return x;
    }
};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends