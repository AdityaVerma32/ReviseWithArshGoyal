#include<bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define li long int
#define lli long li
#define ulli unsigned lli
#define uli unsigned li
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

class Solution1 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(n == 1) return cardPoints[0];
        vector<int> sum(n);
        sum[0] = cardPoints[0];
        for(int i=1;i<n;i++) sum[i] = sum[i-1] + cardPoints[i];
        int z = (n-k-1);
        int subSum = sum[z];

        int i=0;
        while(z<n){
            subSum=min(subSum,sum[z]-sum[i]);
            z++;
            i++;
        }
        // while(++z){
        //     if(z == n) break;
        //     if((z-k-1) >= 0 ) subSum = min(subSum,(sum[z]-sum[z-k-1]));
        //     else subSum = min(subSum, sum[z]);
        // }
        return sum[n-1] - subSum;
    }
};

class Solution2 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int z = n-k;
        vector<int> sum(n);
        sum[0] = cardPoints[0];
        for(int i =1;i<n;i++) sum[i] = sum[i-1] + cardPoints[i];
        int ssum=INT_MAX;
        for(int i =0;i<=n-z;i++){
            cout << "i = " << i << " ";
            for(int j = i+z-1;j<n;j++){
                cout << "j = " << j << " ";
                int tsum;
                if(i == 0) tsum = sum[j];
                else tsum = sum[j] - sum[i];
                cout << "tsum = " << tsum << " ";
                cout << "ssum = " << ssum << " ";
                ssum = min(ssum,tsum);
                cout << "final ssum = " << ssum << endl;
            }
        }

        cout << "sum[n-1] = " << sum[n-1] << " ssum = " << ssum << " sum[n-1] - ssum = " << sum[n-1] - ssum << endl << endl;
        return sum[n-1] - ssum;
    }
};

int main(){
    int n,tar;
    cin >> n;
    vi nums(n);
    FOR(i,n) cin >> nums[i];
    cin >> tar;
    Solution2 obj = Solution2();
    int ans = obj.maxScore(nums,tar);
    cout << "Ans = " << ans << endl;
    return 0;
}