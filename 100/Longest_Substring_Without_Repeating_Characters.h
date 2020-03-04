#include<header.h>
#include<unordered_map>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //常见的一些特殊情况的判断
        if(s.size() == 0)   return 0;
        if(s.size() == 1)   return 1;
        //用来记录某个字符在当前串出现的位置。如果为-1或者不存在表明串中没有
        unordered_map<char,int> flag;
        int start = 0;
        flag[s[start]] = 0;
        int end = 1;
        int max_length = 1;
        int length = 1;
        while(end != s.size()){
            if( flag.count(s[end]) && flag[s[end]] != -1){
                //表明已经有重复的了
                int index = flag[s[end]];
                for(int i = start; i <= index; i++){
                    flag[s[i]] = -1;
                }
                if(length > max_length) max_length = length;
                length = (end - index);
                start = index + 1;
                flag[s[end]] = end;
            }else{
                //表明没有重复的，直接往里塞
                flag[s[end]] = end;
                length++;
            }
            //向后移一位
            end++;
        }
        //这里需要保证 如果到尾部都没有重复的值的话 max_length就一直没有赋值
        return (max_length>length)?max_length:length;
    }
};