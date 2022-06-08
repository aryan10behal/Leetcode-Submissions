class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0,j = s.size()-1;
        int f = 0;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                f = 1;
                break;
            }
            i++, j--;
        }
        if(f)
            return 2;
        return 1;
    }
};