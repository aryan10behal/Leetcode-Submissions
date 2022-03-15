class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans = "";
        for(char x: s)
        {
            if(x == '(')
            {
                st.push(x);
                ans+=x;
            }
            else if(x == ')')
            {
                if(st.size() != 0)
                {
                    st.pop();
                    ans+=x;
                }
            }
            else
            {
                ans += x;
            }
        }
        int val = 0;
        for(int i = ans.size()-1;i>=0;i--)
        {
            if(ans[i] == ')')
                val++;
            if(ans[i] == '(')
            {
                if(val == 0)
                    ans.erase(i, 1);
                else
                    val--;
            }
        }
        return ans;
    }
};