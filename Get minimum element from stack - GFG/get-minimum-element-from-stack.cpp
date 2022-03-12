// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s, s2;
    int mn = 1e9;
    public:
       /*returns min element from stack*/
       int getMin(){
            if(s.size() == 0)
                return -1;
            return mn;
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(s.size() == 0)
                return -1;
            int a = s.top();
            if(s.top() == mn)
            {
                int new_mn = 1e9;
                s.pop();
                while(s.size())
                {
                    if(s.top() < new_mn)
                    {
                        new_mn = s.top();
                    }
                    s2.push(s.top());
                    s.pop();
                }
                while(s2.size())
                {
                    s.push(s2.top());
                    s2.pop();
                }
                a = mn;
                mn  = new_mn;
            }
            else
                s.pop();
            return a;
       }
       
       /*push element x into the stack*/
       void push(int x){
           s.push(x);
           mn = min(mn, x);
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends