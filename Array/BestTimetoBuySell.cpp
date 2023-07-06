// beast time to buy and sell stocks
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int i=0;
        int j=1;
        int n=prices.size();
        while(j<n){
            if(prices[i]>prices[j]){
                i=j;
            }else{
                ans=max(prices[j]-prices[i],ans);
            }
            j++;
        }
        return ans;
    }
};