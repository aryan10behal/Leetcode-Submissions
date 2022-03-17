class Solution {
public:
    int find(string s)
    {
        if(s.size() == 0)
            return 0;
        if(s.size() == 2)
            return 1;
        stack<char> st;
        st.push(s[0]);
        string sub = "";
        int ans = 0;
        int i = 0;
        for(i = 1;i<s.size();i++)
        {
            if(s[i] == ')')
            {
                st.pop();
                if(st.size() == 0)
                    break;
            }
            else
            {
                st.push('(');
            }
        }
        if(i == 1)
            return 1+find(s.substr(i+1));
        return 2*find(s.substr(1, i-1)) + find(s.substr(i+1));
    }
    int scoreOfParentheses(string s) {
        return find(s);
    }
};