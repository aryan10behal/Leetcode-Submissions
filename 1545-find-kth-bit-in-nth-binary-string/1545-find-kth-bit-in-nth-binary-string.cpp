class Solution {
public:
    char findKthBit(int n, int k) {
        
        // if k is 1, we know it is 0.. given in question
        if(k == 1)
            return '0';
        
        // if k was a 1 that was added in middle with going from Si-1 to Si
        if((k&(k-1)) == 0)
            return '1';
        k--;
        int x = 1;
        
        // storing total string length in x
        while(n--)
        {
            x<<=1;
        }
        x--;
        
        // So we will reverse the process of string formation...
        // the general approach is that we will reduce the string size to half at every iteration
        // till the time string size is 1.. that is.. the string becomes the initial '0'
        // at each step, if kth bit is in 2nd half, the reverse and invert operation will take placee.. So apply them..
        // if kth bit is in 1st half, then it stays the same... no operation needed..
        
        // now lets assume that kth bit is 1... and let z represent the kth bit
        // now we will try to reduce k to 1st bit while applying the given rules..
        // if z becomes 0 (at last when it is reduced to 1st bit), then initially z being 1 at kth was true so return 1
        // else if finally z becomes 1, then our assumption was opposite to answer so just return 0...
        int z = 1;
        while(x!=1)
        {
            // if at any point, k becomes that bit at which 1 was added while going from Si-1 to Si, then break the loop and put an extra 
            // invert operation....
            if((k&(k+1)) == 0 && k == x/2)
            {
                z^=1;
                break;
            }
            // if k is in first half of the string, we know that no changes happen to it in this iteration of halving the string...
            // But if k is in 2nd half, map k to the number from which it came!!! also invert it...
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