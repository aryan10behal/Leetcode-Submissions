class Solution {
public:
   int maximumUnits(vector<vector<int>>& a, int s) {
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<a.size(); i++)
        {
            pq.push({a[i][1],a[i][0]}); //a[i][0] = boxes, a[i][1] = unitsPerBox
                                        // s = trcukSize;
        }
        int sm=0,res=0;
        while(sm<=s and pq.size()>0)
        {
            pair<int,int>p=pq.top();
           if(sm+p.second<=s)
           {   
               res+=p.first*p.second;
               cout<<res;
               sm+=p.second;
           }
            else{
                int r=s-sm;
                res+=r*p.first;
                sm=s+1;
            }
            pq.pop();
            
        }
        return res;
    }
};