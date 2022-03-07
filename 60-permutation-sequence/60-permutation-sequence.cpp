class Solution {
public:
    void permute(string &v, int &k, int l, int h, string &ans)
    {
        if(k<0)
            return;
        if(l == h-1)
        {
            k--;
            if(k == 0)
                ans = v;
            return;
        }
        for(int i = l;i<h;i++)
        {
            {
                char s = v[i];
                v[i] = v[l];
                v[l] = s;
            }
            sort(v.begin()+l+1, v.end());
            permute(v, k, l+1, h, ans);
            if(k<0)
                return;
            sort(v.begin()+l+1, v.end());
            {
                char s = v[i];
                v[i] = v[l];
                v[l] = s;
            }
        }
    }
    string getPermutation(int n, int k) {
        string v = "";
        string ans = "";
        for(int i=1;i<=n;i++)
            v += (i+'0');
        permute(v, k, 0, n, ans);
        return ans;
    }
};