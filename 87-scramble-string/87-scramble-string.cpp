class Solution {
public:
    bool help(string s1, string s2, int l, int h, map<pair<string, string>, bool> &m)
    {
        if(s1 == s2)
            return true;
        if(l > h)
            return false;
        if(l==h)
            return s1[l] == s2[l];
        if(m.find({s1,s2}) != m.end())
            return m[{s1,s2}];
        if(h-l == 1)
        {
            bool a = ((s1[l] == s2[l] and s1[h] == s2[h]) or (s1[h] == s2[l] and s1[l] == s2[h]));
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
        for(int i = l;i<=h;i++)
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
            if(f == 1 && i!=h)
                p.push_back(i);
        }
        for(int i = 0;i<p.size();i++)
        {
            string aa = s1.substr(l, p[i]+1);
            string bb = s2.substr(l, p[i]+1);
            string cc = s1.substr(p[i]+1);
            string dd = s2.substr(p[i]+1);
            
            bool a = help(aa, bb, 0, aa.size()-1, m);
            bool b = help(cc, dd, 0, cc.size()-1, m);
            if(a && b)
            {
                m[{s1,s2}] = true;
                return true;
            }
        }
        
//      ----------------------------------------
        
        vector<int> a1(26, 0), b1(26, 0);
        vector<int> p2;
        for(int i = l, j = h;i<=h;i++, j--)
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
            if(f == 1 && i!=h)
            {
                //cout<<i<<endl;
                p2.push_back(i);
            }
        }
        for(int i = 0;i<p2.size();i++)
        {
            string xx = s2.substr(h-p2[i], p2[i]+1);
            string jj = s2.substr(l, h-l-p2[i]);
            string yy = s1.substr(l, p2[i]+1);
            string zz = s1.substr(p2[i]+1, h-l-p2[i]);
            //cout<<yy<<" "<<xx<<" "<<zz<<" "<<jj<<endl;
            bool a = help(yy, xx, 0, yy.size() -1, m);
            bool b = help(zz, jj, 0, zz.size()-1, m);
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
        return help(s1, s2, 0, s1.size()-1, m);
    }
};