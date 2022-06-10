class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ch(256, -1);
        int i = 0, j = 0, n = s.size(), c = 0, m = 0;
        while(i<n)
        {
            if(ch[s[i]] == -1)
            {
                c++;
                ch[s[i]] = i;
                m = max(m, c);
                i++;
            }
            else
            {
                while(j<=ch[s[i]])
                {
                    c--;
                    ch[s[j]] = -1;
                    j++;
                }
            }
        }
        return m;
    }
};