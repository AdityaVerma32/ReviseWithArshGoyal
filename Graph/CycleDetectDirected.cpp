#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Detect cycle in a directed graph using BFS(Kahn's Algorithm).
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                ans.push_back(i);
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        
        return ans.size()!=V;
        
    }

    // Cycle Detection in Directed Graph using Dfs
    bool dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& path){
        vis[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)){
                    return true;
                }
            }else if(path[it]==1){
                    return true;
                }
        }
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return true;
            }
        }
        
        return false;
    }
};