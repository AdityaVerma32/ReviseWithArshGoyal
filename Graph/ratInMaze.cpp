#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    char dir[4]={'R','D','L','U'};
    vector<string> ans;
    
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis,string str,int n){
        if(r==n-1 && c==n-1){
            ans.push_back(str);
            return;
        };
        vis[r][c]=1;
       
        for(int x=0;x<4;x++){
            int ni=r+dr[x];
            int nj=c+dc[x];
            if(ni>=0 && ni<n && nj>=0 && nj<n && vis[ni][nj]==0 && grid[ni][nj]==1){
                dfs(ni,nj,grid,vis,str+dir[x],n);
            }
        }vis[r][c]=0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0 || m[n-1][n-1]==0) return {"-1"};
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        dfs(0,0,m,vis,"",n);
        return ans;
        
    }
};