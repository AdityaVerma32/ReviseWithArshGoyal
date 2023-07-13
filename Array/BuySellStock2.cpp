// There are two cases
// Can buy :- subtract the price
// Can sell :- Add the price

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sol(vector<int>& prices,int buy,int ind,vector<vector<int>>& dp){

        if(ind==prices.size()){
            return 0;
        }

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==1){ //can buy
            int no=sol(prices,1,ind+1,dp);
            int yes=-prices[ind]+sol(prices,0,ind+1,dp);
            return dp[ind][buy]=max(no,yes);
        }else{  // can sell
            int no=sol(prices,0,ind+1,dp);
            int yes=prices[ind]+sol(prices,1,ind+1,dp);
            return dp[ind][buy]=max(no,yes);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return sol(prices,1,0,dp);
    }
};