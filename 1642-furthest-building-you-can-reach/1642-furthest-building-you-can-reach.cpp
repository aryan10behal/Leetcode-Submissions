class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int> &b)
    {
        return a.first < b.first;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<pair<int, int>> diff;
        for(int i = 1;i<heights.size();i++)
        {
            if(heights[i] - heights[i-1] > 0)
            {
                diff.push_back({heights[i] - heights[i-1] , i});
            }
        }
        if(diff.size() == 0)
            return heights.size()-1;
        int l = 0, h = diff.size()-1, ans = -1, mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            vector<pair<int, int>> p(mid+1);
            for(int i = 0;i<=mid;i++)
                p[i] = diff[i];
            sort(p.begin(), p.end(), comp);
            //cout<<l<<" "<<mid<<" "<<h<<endl;
            int pss = 1, b = bricks, lad = ladders;
            for(int i = 0;i<=mid;i++)
            {
                //cout<<b<<" "<<p[i].first<<endl;
                if(b >= p[i].first)
                    b-=p[i].first;
                else if(lad>0)
                    lad--;
                else
                {
                    pss = -1;
                    break;
                }
            }
            //cout<<pss<<endl;
            if(pss == -1)
                h = mid - 1;
            else
            {
                ans = mid;
                l = mid+1;
            }
        }
        if(ans == -1)
           return diff[0].second-1;
        if(ans == diff.size()-1)
            return heights.size()-1;
        return diff[ans+1].second-1;
    }
};