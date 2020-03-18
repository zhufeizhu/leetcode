#include<header.h>

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        bool start = false;
        bool neg = false;
       for(int i = 0; i < str.size(); i++){
            if(str[i] < '0' || str[i] > '9'){
                if(start) break;
                else if(str[i] == ' ' && !start) continue;
                else if(str[i] == '+' && !start){
                    start = true;
                    continue;
                }
                else if(str[i] == '-' && !start){
                    start = true;
                    neg = true;
                    continue;
                }else{
                    break;
                }
            }else{
                start = true;
                res = res*10 + str[i]-'0';
                if(!neg && res > INT_MAX)    return INT_MAX;
                long long temp = INT_MAX;
                temp++;
                if(neg && res > temp)    return INT_MIN;
            }
       }
       return neg?-1*res:res;
};

