class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& nints) {
        int n = ints.size();
        vector<vector<int>> ans;
        int added = 0;
        for(int i = 0;i<n;i++)
        {
            if(added==0 && nints[1] < ints[i][0] && (i==0 || nints[0]>ints[i-1][1]))
            {
                added = 1;
                ans.push_back(nints);
            }
            if(nints[0] <= ints[i][1] && nints[1] >= ints[i][1] or nints[1] >= ints[i][0] and nints[1] <= ints[i][1])
            {
                added = 1;
                int s = min(nints[0], ints[i][0]);
                int e = max(nints[1], ints[i][1]);
                i++;
                nints[0] = 1e9;
                nints[1] = 1e9;
                while(i<n && e>=ints[i][0])
                {
                    e = max(e,ints[i][1]);
                    i++;
                }
                i--;
                vector<int> k = {s, e};
                ans.push_back(k);
            }
            else
                ans.push_back(ints[i]);
        }
        if(added == 0)
            ans.push_back(nints);
        return ans;
    }
};