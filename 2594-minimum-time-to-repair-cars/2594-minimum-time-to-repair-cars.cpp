class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
       long long low=1,high,ma=0;
        for(long long i=0;i<ranks.size();i++){
            ma=max(ma,(long long)ranks[i]);
        }
        high=ma*((long long)cars)*((long long)cars);
        long long ans=0;
        while(low<high){
            long long mid=low+(high-low)/2;
            ans=0;
            for(long long i=0;i<ranks.size();i++){
                long long p=mid/ranks[i];
                long long q=sqrt(p);
                ans+=q;
            }
            if(ans<cars){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return high;
    }
};