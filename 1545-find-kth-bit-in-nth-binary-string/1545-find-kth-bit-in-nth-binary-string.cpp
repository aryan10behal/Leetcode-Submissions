class Solution {
public:
    char findKthBit(int n, int k) {
        if(k == 1)
            return '0';
        if((k&(k-1)) == 0)
            return '1';
        k--;
        int x = 1;
        while(n--)
        {
            x<<=1;
        }
        x--;
        //cout<<x<<endl;
        int z = 1;
        while(x!=1)
        {
            //cout<<x<<" "<<k<<endl;
            if((k&(k+1)) == 0 && k == x/2)
            {
                z^=1;
                break;
            }
            if(k>x/2)
            {
                z^=1;
                k = x/2 - (k - x/2);
            }
            x>>=1;
                
        }
            
        return z==0? '1':'0';
    }
};