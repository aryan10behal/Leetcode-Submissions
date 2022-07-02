class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int xx = 0, yy= 0;
        for(int i=1;i<hc.size();i++)
            xx = max(xx, hc[i] - hc[i-1]);
        for(int i=1;i<vc.size();i++)
            yy = max(yy, vc[i] - vc[i-1]);
        //cout<<xx<<" "<<yy<<endl;
        xx = max(xx, max(hc[0], h - hc[hc.size()-1]));
        yy = max(yy, max(vc[0], w - vc[vc.size()-1]));
        long long a = xx, b = yy;
       // cout<<a<<" "<<b<<endl;
        int m = 1e9+7;
        return (a*b)%m;
    }
};