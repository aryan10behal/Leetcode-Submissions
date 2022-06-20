class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        vector<int> dis_set(n, -1);
        for(int i = 0; i<n;i++)
        {
            if(dis_set[i]!=-1)
                continue;
            for(int j = i+1;j<n;j++)
            {
                if(dis_set[i] == -1 or dis_set[j] == -1)
                {
                    int x = words[i].size()-1, y = words[j].size()-1;
                    while(x>=0 and y>=0)
                    {
                        if(words[i][x] != words[j][y])
                            break;
                        x--, y--;
                    }
                    if(x == -1 or y == -1)
                    {
                        if(x == -1)
                            dis_set[i] = j;
                        else
                            dis_set[j] = i;
                    }
                }
            }
        }
        int ans = 0;
        for(int i =0 ;i<n;i++)
        {
            if(dis_set[i] == -1)
            {
                ans+=words[i].size()+1;
            }
        }
        return ans;
    }
};