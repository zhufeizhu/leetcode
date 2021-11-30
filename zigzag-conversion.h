#include<header.h>
#include<queue>

class Solution {
public:
    string convert(string s, int numRows){
        if(s.empty())   return s;
        if( numRows == 1 )  return s;
        string res = "";
        int length = s.size();
        //times represents how many z
        int times = length / (2*numRows-2);
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j <= times; j++){
                int index = 0;
                if( i == 0 ){
                    index = j * (2 * numRows - 2);
                    if(index < length)  res += s[index];
                }else if( i == numRows -1){
                    index = j * (2 * numRows - 2) + numRows - 1;
                    if(index < length)  res += s[index];
                }else{
                    //not first and last row
                    index = j * (2 * numRows - 2) + i;
                    if(index < length)  res += s[index];
                    index = (j+1) * (2 * numRows - 2) - i;
                    if(index < length)  res += s[index];
                }
            }
        }
        return res;
    }
};

