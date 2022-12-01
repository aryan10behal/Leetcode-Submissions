class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char, int> x;
        int i = 0, j = s.size()-1;
        while(i<j)
        {
            x[s[i++]]++;
            x[s[j--]]--;
        }
        int v = x['a'] + x['A'] + x['e'] + x['E'] + x['i'] +x['I'] + x['O'] + x['o'] + x['u'] + x['U'];
        if(v!=0)
            return false;
        return true;
    }
};