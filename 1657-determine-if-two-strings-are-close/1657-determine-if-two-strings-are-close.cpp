class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> x(26, 0), z(26,0);
        for(char y: word1)
            x[y-97]++;
        for(char y: word2)
            z[y-97]++;
        for(int i=0;i<26;i++)
        {
            if(x[i] >0 && z[i]==0 || z[i]>0 && x[i]==0)
                return false;
        }
        sort(x.begin(),x.end());
        sort(z.begin(),z.end());
        for(int i=0;i<26;i++)
        {
            // cout<<x[i]<<" "<<z[i]<<endl;
            if(x[i]!=z[i])
                return false;
        }
        return true;
    }
};