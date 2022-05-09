class Solution {
public:
    void solve(string d, vector<string> &ans, vector<vector<char>> &key_pad, int i, string& val)
    {
        //cout<<i<<endl;
        if(i == d.size())
        {
            ans.push_back(val);
            return;
        }
        for(char x: key_pad[d[i]-'2'])
        {
            val+=x;
            solve(d, ans, key_pad, i+1, val);
            val.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        vector<vector<char>> key_pad(8, vector<char>());
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                key_pad[i].push_back(i*3+j+'a');
            }
        }
        key_pad[5].push_back('s');
        for(int i=6;i<8;i++)
        {
            for(int j=0;j<3;j++)
            {
                key_pad[i].push_back(i*3+j+'a'+1);
            }
        }
        key_pad[7].push_back('z');
        string val = "";
        solve(digits, ans, key_pad, 0, val);
        return ans;
    }
};