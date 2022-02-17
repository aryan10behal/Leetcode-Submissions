class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int i = 0;
        int n = a.size();
        stack<int> st;
        vector<int> ans;
        while(i<n)
        {
            if(a[i]>0)
                st.push(a[i]);
            else
            {
                while(st.size() && st.top() < abs(a[i]))
                {
                    st.pop();
                }
                if(st.size() == 0)
                {
                    ans.push_back(a[i]);
                }
                else if(st.top() == abs(a[i]))
                {
                    st.pop();
                }
            }
            i++;
        }
        stack<int> tt;
        while(st.size())
        {
            tt.push(st.top());
            st.pop();
        }
        while(tt.size())
        {
            ans.push_back(tt.top());
            tt.pop();
        }
        return ans;
    }
};