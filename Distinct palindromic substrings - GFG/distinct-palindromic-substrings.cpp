// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n = s.size();
        int ans = 0;
        set<string> st;
        for(int i=0;i<n;i++)
        {
            int j = i, k = i+1;
            string z = "";
            while(j>=0 && k<n && s[j] == s[k])
            {
                z = s[j] + z + s[k];
                st.insert(z);
                k++, j--;
            }
        }
        for(int i=0; i<n; i++)
        {
            int j = i-1, k = i+1;
            string z = "";
            z += s[i];
            st.insert(z);
            while(j>=0 && k<n && s[j] == s[k])
            {
                z = s[j] + z + s[k];
                st.insert(z);
                j--, k++;
            }
        }
        return st.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends