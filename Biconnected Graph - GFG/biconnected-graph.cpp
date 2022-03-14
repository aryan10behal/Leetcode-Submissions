// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool find(vector<vector<int>> &graph, int s, vector<int> &disc, vector<int> &low, vector<int> &parent, int &time)
    {
        disc[s] = low[s] = ++time;
        int children = 0;
        for(int x: graph[s])
        {
            if(disc[x] == -1)
            {
                children++;
                parent[x] = s;
                if(find(graph, x, disc, low, parent, time))
                    return true;
                low[s] = min(low[s], low[x]);
                if(parent[s] == -1)
                {
                    if(children>1)
                        return true;
                }
                else
                {
                    if(low[x] > disc[s])
                        return true;
                }
            }
            else if (x != parent[s])
                low[s]  = min(low[s], disc[x]);
        }
        return false;
    }
    int biGraph(int arr[], int n, int e) {
        vector<vector<int>> graph(n, vector<int>());
        for(int i = 0; i<2*e;i+=2)
        {
            graph[arr[i]].push_back(arr[i+1]);
            graph[arr[i+1]].push_back(arr[i]);
        }
        vector<int> disc(n,-1);
        vector<int> low(n, 1e9);
        vector<int> parent(n, -1);
        int time = 0;
        if(find(graph, 0, disc, low, parent, time))
            return false;
        for(int i=0;i<n;i++)
        {
            if(disc[i] == -1)
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends