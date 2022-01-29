// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        string f = "";
        string s = "";
        sort(arr, arr+n);
        for(int i = 0, j = 1; j < n;i+=2, j+=2)
        {
            f += (arr[i]+'0');
            s += (arr[j]+'0');
        }
        string ans = "";
        if((n&1) == 1)
          {
                f += (arr[n-1] + '0');
                 // cout<<f<<" "<<s<<endl;
                int carry = 0;
                for(int i = s.size()-1;i>=0;i--)
                {
                    int val = f[i+1] - '0' + s[i] - '0' + carry;
                    if(val/10 > 0)
                        carry = 1;
                    else
                        carry = 0;
                    val = val%10;
                    ans+= (val+'0');
                }
                int val = f[0] - '0' + carry;
                ans += (val%10 + '0');
                if(val/10)
                    ans += '1';
                
          }
        else
        {
            int carry = 0;
            for(int i = s.size()-1;i>=0;i--)
                {
                    int val = f[i] - '0' + s[i] - '0' + carry;
                    if(val/10 > 0)
                        carry = 1;
                    else
                        carry = 0;
                    val = val%10;
                    ans+= (val+'0');
                }
            if(carry)
                ans+= carry + '0';
        }
        //cout<<ans<<endl;
        int i = 0;
        string x = "";
        reverse(ans.begin(), ans.end());
        while(i<ans.size() && ans[i]=='0')
           {
               i++;
           }
        while(i<ans.size())
        {
            x+= ans[i];
            i++;
        }
        return x;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends