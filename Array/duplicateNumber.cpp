// Using Bit Manipulation

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        n--;
        vector<int> one(32,0),two(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j] & 1<<i ){
                    one[i]++;
                }
            }
        }

        for(int i=0;i<32;i++){
            for(int j=1;j<=n;j++){
                if(j & (1<<i) ){
                    two[i]++;
                }
            }
        }

        int ans=0;
        for(int i=0;i<32;i++){
            int t=one[i]-two[i];

            if(t>0){
                ans=ans|(1<<i);
            }
        }
        return ans;

    }
};