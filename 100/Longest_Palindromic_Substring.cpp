// 最长回文子串
#include "header.h"

class Solution{
public:
    string longestPalindrome(string s){
        int n = s.size();

        if(n < 2) return s;

        vector<vector<int>> dp(n,vector<int>(n));

        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        int max = 1, pos = 0;

        int end = 0;
        for(int l = 2; l <=n; l++){//l表示子串的长度 长度从2-n
            for(int begin = 0; begin < n; begin++){
                end = begin + l - 1;
                if(end >= n) break;//后面的肯定不符合

                if(s[begin] != s[end]){
                    dp[begin][end] = -1;
                }else{
                    if(l <= 3){
                        dp[begin][end] = 1;
                    }else{
                        dp[begin][end] = dp[begin+1][end-1];
                    }
                }

                if(dp[begin][end] == 1 && l > max){
                    max = l;
                    pos = begin;
                }

            }
        }

        return s.substr(pos,max);
    }    
};

int main(){
    Solution solution;
    string s("aba");
    string res = solution.longestPalindrome(s);
    cout<<res<<endl;
    return 0;
}