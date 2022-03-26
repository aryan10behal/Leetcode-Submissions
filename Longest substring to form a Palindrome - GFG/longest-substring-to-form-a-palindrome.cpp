// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int longestSubstring(string s) {
    map<int, int> index;
    int answer = 0; 
    int n = s.size();
    int mask = 0; 
    index[mask] = -1; 

    for(int i = 0; i < n; i++) 
    { 
    
        int temp = (int)s[i] - 97; 
        mask ^= (1 << temp); 

        // If a mask is present in the index 
        // Therefore a palindrome is 
        // found from index[mask] to i 
        if (index[mask]) 
        { 
            answer = max(answer, 
                         i - index[mask]); 
        } 
        else
            index[mask] = i; 
        for(int j = 0; j < 26; j++) 
        { 
            int mask2 = mask ^ (1 << j); 
            if (index[mask2]) 
            { 
                answer =max(answer, i - index[mask2]); 
            } 
        } 
    } 
    return answer;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}  // } Driver Code Ends