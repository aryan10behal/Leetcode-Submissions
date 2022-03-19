// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        vector<int> x(26, -1);
        for(int i = 0;i<a.size();i++)
        {
            if(x[a[i]-'a'] == -1)
                x[a[i]-'a'] = i;
        }
        char aa = '#', bb = '#';
        for(int i = 0;i<a.size();i++)
        {
            for(int j = 0;j<a[i]-'a';j++)
            {
                if(x[j]!=-1 and x[j] > i)
                {
                    aa = a[i];
                    bb = j+'a';
                    for(int kk = 0;kk<a.size();kk++)
                    {
                        if(a[kk] == aa)
                            a[kk] = bb;
                        else if(a[kk] == bb)
                            a[kk] = aa;
                    }
                    return a;
                }
            }
        }
        return a;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends