#include "header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int maxPos = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(i > maxPos) break;
            if((nums[i] + i) >= n) {
                flag = true;
                break;
            }
            if(maxPos < (nums[i] + i)){
                maxPos = nums[i] + i;
            } 
        }
        return flag;
    }
};

int main(){
    Solution solution;
    vector<int> v = {3,2,1,0,4};
    cout<<solution.canJump(v)<<endl;
}