class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long x = rec2[0] - rec1[2];
        long long y = rec2[2] - rec1[0];
        long long  u = rec2[1] - rec1[3];
        long long v = rec2[3] - rec1[1];
        if(x*y < 0 && u*v < 0)
            return true;
        return false;
    }
};