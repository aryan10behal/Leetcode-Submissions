class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.size();
        if(n==1)
            return "";
        int i = 0;
        while(i<n and p[i] == 'a')
            i++;
        if(i == n or (i == n/2 and n%2 == 1))
            p[n-1] = 'b';
        else
            p[i] = 'a';
        return p;
    }
};