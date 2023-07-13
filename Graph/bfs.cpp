//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> ans;
        vector<int> vis(V,0);
        q.push(0);
        vis[0]=1;
        ans.push_back(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    ans.push_back(it);
                    q.push(it);
                }
                
            }
        }
        
        return ans;
    }
};

