class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n), r(n);
        l[0] = -1;
        r[n-1] = -1;
        stack<pair<int, int>> s;
        for(int i=0;i<n;i++)
        {   
            while(s.size() && s.top().first >= heights[i])
            {
                s.pop();
            }
            if(s.empty())
                l[i] = -1;
            else
                l[i] = s.top().second;
            s.push({heights[i], i});
        }
        while(s.size())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {   
            while(s.size() && s.top().first >= heights[i])
            {
                s.pop();
            }
            if(s.empty())
                r[i] = n;
            else
                r[i] = s.top().second;
            s.push({heights[i], i});
        }
        int m =0;
        for(int i = 0;i<n;i++)
        {
            m=max(m,(r[i]-l[i]-1)*heights[i]);
        }
        return m;
    }
};