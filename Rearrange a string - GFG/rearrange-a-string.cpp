// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
           string ans = "";
           int sum = 0;
           for(char x: str)
           {
               if(x>='A' && x<='Z')
                    ans+=x;
                else
                    sum += (x - '0');
           }
           string k = "";
           while(sum!=0)
           {
               k += sum%10 + '0';
               sum/=10;
           }
           sort(ans.begin(), ans.end());
           reverse(k.begin(), k.end());
           ans += k;
           return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends