#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Detecting Cycle in undirected graph using BFS.
    bool isCycle(int V, vector<int> adj[]) {
        queue<pair<int,int>> q;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                q.push({i,-1});
                while(!q.empty()){
                    int node=q.front().first;
                    int last=q.front().second;
                    q.pop();
                    vis[node]=1;
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            q.push({it,node});
                        }else if(last!=it){
                            return true;
                        }
                    }
                }
            }
            
        }
        return false;
    }

    // Cycle Detection in Undirected Graph using DFS

    bool dfs(int node,vector<int> adj[],vector<int>& vis,int last){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,node)){
                    return true;
                }
            }else if(last!=it){
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};