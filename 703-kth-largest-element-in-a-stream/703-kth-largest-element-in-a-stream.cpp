class KthLargest {
public:
    multiset<int> m;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x = k;
        for(int g: nums)
            m.insert(g);
    }
    
    int add(int val) {
        m.insert(val);
        int ind = 1;
        for (auto i = m.rbegin(); i != m.rend(); ++i) {
            if(ind == x)
                return *i;
            ind++;
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */