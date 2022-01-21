class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, cur_wid = 0;
        vector<int> ans(2);
        for(char x: s)
        {
            if(cur_wid + widths[x-'a'] > 100)
            {
                lines++;
                cur_wid = 0;
            }
            cur_wid+= widths[x-'a'];
        }
        ans[0] = lines;
        ans[1] = cur_wid;
        return ans;
    }
};