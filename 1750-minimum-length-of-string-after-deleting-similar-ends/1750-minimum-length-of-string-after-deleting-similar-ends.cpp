#include<bits/stdc++.h>
class Solution {
public:
    int minimumLength(string s) {
        int ans=s.length();
        int i=0,j=s.length()-1;
        while(i<j)
        {
            char a = s[i], b = s[j];
            if(a!=b)
                break;
            while(i <= j && a == s[i])
            {
                i++;
                ans--;
            }
            while(j>=i && b == s[j])
            {
                ans--;
                j--;
            }
        }
        return ans;
    }
};