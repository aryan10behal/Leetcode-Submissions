class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int> ch(26, 0);
        for(char x: r)
            ch[x-'a']--;
        for(char x: m)
            ch[x-'a']++;
        for(int i = 0;i<26;i++)
        {
            if(ch[i] < 0)
                return false;
        }
        return true;
    }
};