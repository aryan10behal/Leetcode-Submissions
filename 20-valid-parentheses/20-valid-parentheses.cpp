class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char x: s)
        {
            if(x == '(' or x == '[' or x == '{')
            {
                st.push(x);
            }
            else
            {
                if(st.size() == 0)
                    return false;
                if((st.top() == '(' && x!= ')') || (st.top() == '[' && x!= ']') || (st.top() == '{' && x!= '}'))
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};