class Solution {
public:
    int gcd(int a, int b)
    {
        if(a == 0 or b == 0)
            return a==0?b:a;
        if(a%b ==0 or b%a==0)
            return a%b==0?b:a;
        if(a<b)
            return gcd(b%a, a);
        return gcd(a%b, b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(int x: nums)
        {
            while(st.size())
            {
                long long a = st.top();
                int y = gcd(a, x);
                if(y!=1)
                {
                    st.pop();
                    x = (x*a)/y;
                }
                else
                    break;
            }
            st.push(x);
        }
        vector<int> ans(st.size());
        int i = 0;
        while(st.size())
         {
              ans[i++]= st.top();
              st.pop();
         }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};