class Solution {
public:
        
    string getPermutation(int n, int k) {
        string res = "";
        int fact=1;
        vector<int> arr;
        
        for(int i=1; i<n;i++) {
            fact =fact*i;
            arr.push_back(i);   
        }
        arr.push_back(n);
        k=k-1;
        
        while(true) {
            res +=  (arr[k/fact] + '0');
            arr.erase(arr.begin() + k/fact);
            if(arr.size()==0) {
                break;
            }
            k = k%fact;
            fact = fact/arr.size();
        }
        
        return res;
    }
};