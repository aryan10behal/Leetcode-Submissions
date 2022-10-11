class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<long long> smaller(n, -1e18);
        for(int i = 0;i<n;i++)
        {
            while(st.size() and st.top() >= nums[i])
                st.pop();
            if(st.size())
                smaller[i] = st.top();
            st.push(nums[i]);
        }
        while(st.size())
            st.pop();
        for(int i = n-1;i>=0;i--)
        {
            while(st.size() and st.top()<=nums[i])
                st.pop();
            if(st.size() and smaller[i] != -1e18)
                return true;
            st.push(nums[i]);
        }
        return false;
    }
};