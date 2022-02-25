// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
        int i=0,j=0;
        int n = s1.size();
        while(i<n && j<n){
            while(i<n && s1[i] == '#'){
                i += 1;
            }
            while(j<n && s2[j] == '#'){
                j += 1;
            }
            if(i<n && j<n){
            
                if(s1[i] != s2[j]){
                    return "No";//cannot crossover
                }
                else{
                    if(s1[i] == 'B' && i>j){
                        //B cannot move left
                        return "No";
                    }
                    else if(s1[i] == 'A' && i<j){
                        //A cannnot move right
                        return "No";
                    }
                    else{
                        i += 1;
                        j += 1;
                    }
                }
            }
            else{
                break;   
            }
        }
        return (i==n || j==n)?"Yes":"No";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends