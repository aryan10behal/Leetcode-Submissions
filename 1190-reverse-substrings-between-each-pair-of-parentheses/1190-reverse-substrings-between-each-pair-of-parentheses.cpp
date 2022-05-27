class Solution {
public:
    void helper(string& s, int i = 0){
        if(i>=s.size()) return;
        if(s[i]=='('){
            auto it = s.find(')', i+1);
            auto next = s.find('(', i+1);
            if(next != string::npos && next<it)
                helper(s, next);
            
            it = s.find(')', i+1);
            reverse(s.begin()+i, s.begin()+it+1);
            s.erase(i,1);
            s.erase(it-1,1);
            helper(s, i);
        }
        else helper(s, i+1);
    }
    string reverseParentheses(string s) {
        helper(s);
        return s;
    }
};