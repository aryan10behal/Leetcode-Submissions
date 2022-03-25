class Solution {
public:
    int brokenCalc(int value, int target) {
        int ans = 0;
        while(target > value)
        {
            ans++;
            if(target%2 == 0)
                target /= 2;
            else
                target+=1;
        }
        return ans + value - target;
    }
};