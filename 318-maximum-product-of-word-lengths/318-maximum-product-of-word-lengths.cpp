class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> v;
        for(string x: words)
        {
            int k = 0;
            for(char y: x)
                k|=(1<<(y-'a'));
            v.push_back(k);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(!(v[i] & v[j]))
                    ans = max(ans, (int)(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};