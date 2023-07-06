// Two pointer

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            if(nums[i]!=nums[j]){
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        int ans=i+1;
        i++;
        for(;i<n;i++){
            nums[i]=0;
        }
        return ans;
    }
};