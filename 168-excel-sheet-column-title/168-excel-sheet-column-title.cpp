class Solution {
public:
    string convertToTitle(int c) {
        string a = "";
        vector<char> x(26);
        for(int i = 0;i<26;i++)
            x[i] = 'A' + i;
        while(c!=0)
        {
            int r = c%26;
            if(r == 0)
            {
                a.push_back('Z');
                c = c/26 -1;
            }
            else
            {
                a.push_back(r-1+'A');
                c /= 26;
            }
        }
        reverse(a.begin(), a.end());
        return a;
    }
};