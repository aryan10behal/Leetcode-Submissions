class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a, b;
        for(char x: s)
        {
            if(x == '#')
            {
                if(a.size())
                    a.pop();
            }
            else
                a.push(x);
        }
        for(char x: t)
        {
             if(x == '#')
            {
                if(b.size())
                    b.pop();
            }
            else
                b.push(x);
        }
        if(a.size() != b.size())
            return false;
        while(a.size() and a.top() == b.top())
            a.pop(), b.pop();
        return a.size()!=0 or b.size()!=0? false:true;
    }
};