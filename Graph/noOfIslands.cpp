#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;

        for(int x=0;x<4;x++){
            int ni=i+dr[x];
            int nj=j+dc[x];
            if(ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj]==0 && grid[ni][nj]=='1'){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }        
        return ans;

    }
};