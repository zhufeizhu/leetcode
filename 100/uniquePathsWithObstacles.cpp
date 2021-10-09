#include "header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n));

        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1) dp[i][0] = 0;
            dp[i][0] = 1;
        }

        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 1) dp[0][i] = 0;
            dp[0][i] = 1;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};