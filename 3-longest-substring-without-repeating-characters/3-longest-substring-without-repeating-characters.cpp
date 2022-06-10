class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_map<char, int> o;
        long long l=0,max=0,k=0,i=0;
        while(i<s.length() &&k<s.length())
        {
           if(o.find(s[i])==o.end())
            {
                o[s[i]]=i;
                l++;
                if(l>max)
                    max=l;
               i++;
            }
            else
            {
                while(k<=o[s[i]])
                {
                    l--;
                    o.erase(s[k]);
                    k++;
                }
                l++;
                cout<<l<<endl;
                o[s[i]]=i;
                i++;
            }  
        }
        return max;
    }
};