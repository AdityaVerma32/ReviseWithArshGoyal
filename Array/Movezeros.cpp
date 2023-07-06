// Adding all zeros to end
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int fast=0;
        int slow=0;

        while(fast<n){
            if(nums[fast]!=0){
                swap(nums[fast],nums[slow]);
                slow++;
            }
            fast++;
        }

        while(slow<n){
            nums[slow++]=0;
        }        
    }
};