class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> alp(26, 0);
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if(m>n)
            return ans;
        vector<int> palp(26, 0);
        for(char x: p)
            palp[x-'a']++;
        int i = 0;
        while(i<n)
        {
            if(i < m - 1)
            {
                alp[s[i] - 'a']++;
                i++;
            }
            else
            {
                alp[s[i]-'a']++;
                int f = 0;
                for(int j = 0;j<26;j++)
                {
                    if(alp[j] != palp[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f == 0)
                    ans.push_back(i-m + 1);
                alp[s[i-(m-1)]-'a']--;
                i++;
            }
        }
        return ans;
    }
};