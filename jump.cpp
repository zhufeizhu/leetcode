#include "header.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = 0;

        for(int i = 1; i < n; i++) dp[i] = -1;
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i]; j++){
                if((i + j) >= n) break;
                if(dp[i+j] == -1) dp[i+j] = dp[i] + 1;
                else{
                    if(dp[i+j] > (dp[i] + 1)) dp[i+j] = dp[i] + 1;
                }
            }
        }

        return dp[n-1];
    }
};

int main(){
    Solution solution;
    vector<int> v = {2,3,1,1,4};
    cout<<solution.jump(v)<<endl;
}