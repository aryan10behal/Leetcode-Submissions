class Solution {
public:
    int compress(vector<char>& chars) {
        string x = "";
        int i = 0;
        while(i<chars.size())
        {
            char k = chars[i];
            int val = 0;
            while(i<chars.size() and chars[i] == k)
            {
                val++;
                i++;
            }
            x += k;
            if(val > 1)
                x += to_string(val);
        }
        i = 0;
        while(i<x.size())
        {
            chars[i] = x[i];
            i++;
        }
        return x.size();
    }
};