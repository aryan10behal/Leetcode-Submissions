class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        unordered_map<char, int> xx;
        xx['a'] = 0;
        xx['e'] = 1;
        xx['i'] = 2;
        xx['o'] = 3;
        xx['u'] = 4;
        int num = 0, ans = 0;
        m[num] = -1;
        for(int i = 0;i<s.size();i++)
        {
            if(xx.find(s[i]) != xx.end())
                num^=(1<<xx[s[i]]);
            if(m.find(num) != m.end())
                ans = max(ans, i - m[num]);
            else
                m[num] = i;
        }
        return ans;
    }
};