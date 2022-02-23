class FindSumPairs {
    vector<int> a, b;
    map<int, int> m;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for(int j = 0;j<b.size();j++)
        {
            m[b[j]]++;
        }
    }
    
    void add(int index, int val) {
        m[b[index]]--;
        m[b[index] + val]++;
        b[index]+=val;
    }
    
    int count(int tot) {
        int c = 0;
        for(int i=0;i<a.size();i++)
        {
            c+= m[tot - a[i]];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */