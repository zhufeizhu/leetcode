#include "header.h"

#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> maxs(n);
        maxs[0] = 0;
        int min = prices[0];
        for(int i = 1; i < n; i++){
            maxs[i] = prices[i] - min;
            if(prices[i] < min){
                min = prices[i];
            }
        }

        std::sort(maxs.begin(),maxs.end(),[](int a, int b){
            return a > b;
        });

        return maxs[0];
    }
};

int main(){
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    int min = solution.maxProfit(prices);
    cout<<min<<endl;
}