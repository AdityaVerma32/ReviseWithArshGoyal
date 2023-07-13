
#include<bits/stdc++.h>
using namespace std;

//  |_|_|_|_|_|_|
//     a      b
//      let a%k=m and b%k=m 
//      where a and b are the sum upto index i and j
//      then (b-a)%k = (b%k - a%k) %k
//                   = (m-m)%k=0

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int sum=0;
        int n=nums.size();
        vector<int> mod(k,0);
        mod[0]=1;
        for(int i=0;i<n;i++){
            sum=(sum + nums[i]%k + k)%k;
            ans+=mod[sum];
            mod[sum]++;
        }

        return ans;
    }
};