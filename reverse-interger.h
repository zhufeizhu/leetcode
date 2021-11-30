#include<header.h>

class Solution {
public:
    int reverse(int x) {
        if(x == 0)  return 0;
        if(x == -2147483648) return 0;
        long long res = 0;
        bool neg = false;
        if(x < 0) {
            x = -x; 
            neg = true;
        }

        bool not_zero = false;
        while(x != 0){
            int temp1 = x/10;
            int temp2 = x%10;
            x = temp1;
            if(temp2 != 0 && !not_zero){
                res += temp2;
                not_zero = true;
            }else{
                res = res*10 + temp2;
            }
        }
        long long bit = 1;
        bit = bit<<31;
        if(!neg && res > bit-1 ) return 0;
        if(neg && res > bit) return 0;
        return neg?-1*res:res;
    }
};

