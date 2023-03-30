class Solution {
public:
    bool help(string s1, string s2, map<pair<string, string>, bool> &m)
    {
        if(s1 == s2)
            return true;
        int n = s1.size();
        if(n == 1)
            return s1[0] == s2[0];
        if(m.find({s1,s2}) != m.end())
            return m[{s1,s2}];
        if(n == 2)
        {
            bool a = ((s1[0] == s2[0] and s1[1] == s2[1]) or (s1[1] == s2[0] and s1[0] == s2[1]));
            m[{s1, s2}] = a;
            return a;
        }
        string f = s1;
        string g = s2;
        sort(f.begin(), f.end());
        sort(g.begin(), g.end());
        if(f!=g)
            return false;
        vector<int> a(26, 0), b(26, 0);
        vector<int> p;
        for(int i = 0;i<n;i++)
        {
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
            int f = 1;
            for(int j = 0;j<26;j++)
            {
                if(a[j] != b[j])
                {
                    f = 0;
                    break;
                }
            }
            if(f == 1 && i!=n-1)
                p.push_back(i);
        }
        
        // checking for s = x+y
        for(int i = 0;i<p.size();i++)
        {
            string aa = s1.substr(0, p[i]+1);
            string bb = s2.substr(0, p[i]+1);
            string cc = s1.substr(p[i]+1);
            string dd = s2.substr(p[i]+1);
            
            bool a = help(aa, bb, m);
            bool b = help(cc, dd, m);
            if(a && b)
            {
                m[{s1,s2}] = true;
                return true;
            }
        }
        
//      ----------------------------------------
        // checking for s = y + x
        vector<int> a1(26, 0), b1(26, 0);
        vector<int> p2;
        for(int i = 0, j = s1.size()-1;i<n;i++, j--)
        {
            a1[s1[i]-'a']++;
            b1[s2[j]-'a']++;
            int f = 1;
            for(int j = 0;j<26;j++)
            {
                if(a1[j] != b1[j])
                {
                    f = 0;
                    break;
                }
            }
            if(f == 1 && i!=n-1)
            {
                p2.push_back(i);
            }
        }
        for(int i = 0;i<p2.size();i++)
        {
            string xx = s2.substr(n-1-p2[i], p2[i]+1);
            string jj = s2.substr(0, n-1-p2[i]);
            string yy = s1.substr(0, p2[i]+1);
            string zz = s1.substr(p2[i]+1, n-1-p2[i]);
            bool a = help(yy, xx, m);
            bool b = help(zz, jj,  m);
            if(a && b)
            {
                m[{s1,s2}] = true;
                return true;
            }
        }
        m[{s1,s2}] = false;
        return false;
    }
    bool isScramble(string s1, string s2) {
        map<pair<string, string>, bool> m;
        return help(s1, s2, m);
    }
};