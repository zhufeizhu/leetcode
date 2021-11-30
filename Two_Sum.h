#include<header.h>
#include<unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            int res = target - nums[i];
            if(m.count(res)){
                return {m[res],i};
            }else{
                m[nums[i]] = i;
            }
        }
        return {};
    }
};