// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string> x;
        int n = S.size();
        int i = 0;
        while(i<n)
        {
            string m = "";
            while(i<n && S[i]!='.')
            {
                m+=S[i];
                i++;
            }
            x.push_back(m);
            i++;
        }
        string ans = "";
        for(int i = x.size()-1;i>=0;i--)
        {
            ans+=x[i];
            ans+=".";
        }
        ans.pop_back();
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends