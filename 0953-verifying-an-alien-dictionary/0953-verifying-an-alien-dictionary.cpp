class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int k = 0;
        for(char x: order)
            mp[x] = k++;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                int k = words[i].size(), l = words[j].size();
                int x = 0, y = 0;
                while(x<k and y<l)
                {
                    if(mp[words[i][x]] > mp[words[j][y]])
                        return false;
                    if(mp[words[i][x]] < mp[words[j][y]])
                        break;
                    // cout<<"YA\n";
                    x++;
                    y++;
                }
                if(y==l and x<k)
                    return false;
            }
        }
        return true;
    }
};