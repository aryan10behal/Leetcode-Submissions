class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        stack<int> st;
        for(int i = 0;i<pushed.size();i++)
        {
            if(pushed[i] == popped[j])
            {

                j++;
                while(st.size() && st.top()==popped[j])
                {
                    j++;
                    st.pop();
                }
            }
            else
            {
                st.push(pushed[i]);
            }
        }
        if(st.size() and j != pushed.size())
            return false;
        return true;
    }
};