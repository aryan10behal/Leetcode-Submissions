class Solution {
public:
    char findTheDifference(string s, string t) {
        int j = 0;
        for(char x: s)
            j^=x;
        for(char x: t)
            j^=x;
        return (char)j;
    }
};