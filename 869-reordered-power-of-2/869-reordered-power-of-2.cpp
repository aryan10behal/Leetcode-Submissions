class Solution {
public:
    void swap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
    bool make_perm(vector<int> &dig, int i, int n)
    {
        if(i == n)
        {
            int j = 0, bit = 0, num = 0;
            if(dig[0] == 0)
                return false;
            while(j<n)
                num = num*10 + dig[j++];
            while(num!=0)
            {
                bit += (num&1);
                num>>=1;
            }
            return (bit == 1);
        }
        for(int x = i;x<n;x++)
        {
            
            swap(dig[x], dig[i]);
            bool a = make_perm(dig, i+1, n);
            if(a){return true;}
            swap(dig[x], dig[i]);
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> dig;
        while(n!=0)
        {
            dig.push_back(n%10);
            n/=10;
        }
        return make_perm(dig, 0, dig.size());
    }
};