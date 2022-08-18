class Solution {
public:
    int countArrangement(int n) {
        vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = i + 1;
        int res = 0;
        help(v, res, 0);
        return res;
    }
    void help(vector<int>& v, int& res, int i) {
        if (i == v.size()) res++;
        else {
            for (int j = i; j < v.size(); j++) {
                swap(v[i], v[j]);
                if (v[i] % (i + 1) == 0 || (i + 1) % v[i] == 0) {
                    help(v, res, i + 1);
                }
                swap(v[i], v[j]);
            }
        }
    }
};