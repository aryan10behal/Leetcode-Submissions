// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  long long fact(long long val)
  {
      if(val == 0)
        return 1;
      long long a = 1;
      for(int i = 1;i<=val;i++)
      {
          a*=i;
      }
      return a;
  }
  void swap(string &x, int i, int j)
  {
      char a = x[i];
      x[i] = x[j];
      x[j] = a;
  }
    long long findRank(string str) {
        string k = str;
        int n = str.size();
        sort(k.begin(), k.end());
        long long ans = 0;
        int added = 1;
        for(int i = 0; i< str.size(); i++)
        {
            long long ind = -1;
            for(int j = 0;j<k.size();j++)
            {
                if(str[i] == k[j])
                {
                    ind = j;
                    break;
                }
            }
            if(ind!=0 and added!=0)
                added = 1;
            long long val = ind*fact(n-i-1) + added;
            added = 0;
            ans += val;
            swap(k, k.size()-1, ind);
            k.pop_back();
            sort(k.begin(), k.end());
            //cout<<ans<<" "<<k<<endl;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends