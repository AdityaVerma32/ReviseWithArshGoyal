#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int cur_color,int color){
        vis[i][j]=1;
        grid[i][j]=color;
        for(int x=0;x<4;x++){
            int ni=i+dr[x];
            int nj=j+dc[x];
            if(ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj]==0 && grid[ni][nj]==cur_color){
                dfs(ni,nj,grid,vis,cur_color,color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int cur_color=image[sr][sc];

        vector<vector<int>> vis(m,vector<int>(n,0));
        
        dfs(sr,sc,image,vis,cur_color,color);

        return image; 
    }
};