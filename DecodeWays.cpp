#include "../header.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);
        if(oneIsOk(s.substr(0,1))){
            dp[0] = 1;
        }else{
            dp[0] = 0;
        }

        if(twoIsOk(s.substr(0,2))){
            dp[1] = 1;
        }else{
            dp[1] = 0;
        }

        if(oneIsOk(s.substr(1,2))){
            dp[1] += dp[0];
        }

        for(int i = 2; i < n; i++){
            dp[i] = 0;

            if(twoIsOk(s.substr(i-1,i+1))){
                dp[i] += dp[i-2];
            }

            if(oneIsOk(s.substr(i,i+1))){
                dp[i] += dp[i-1];
            }
        }
        return dp[n-1];
    }

    bool oneIsOk(string s){
        if(s[0] <= '9' && s[0] > '0'){
            return true;
        }else{
            return false;
        }
    }

    bool twoIsOk(string s){
        if(s[0] == '1'){
            return true;
        }else if(s[0] == '2'){
            if(s[1]>='0' && s[1]<='6'){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};

int main(){
    string s = "12";
    Solution solution;
    cout<<solution.numDecodings(s)<<endl;
    return 0;
}