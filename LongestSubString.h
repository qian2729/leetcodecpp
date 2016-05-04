//
// Created by 刘宗前 on 16/4/24.
//

#ifndef LEETCODE_LONGESTSUBSTRING_H
#define LEETCODE_LONGESTSUBSTRING_H
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> maps;
        map<char,int>::iterator it;
        int maxAns = 0;
        int lastPos = -1;

        for(int i = 0;i < s.size(); ++i){
            it = maps.find(s[i]);
            if(i == 9){
                cout << i;
            }
            if(it == maps.end() || it->second <= lastPos ){
                maxAns = max(maxAns, i - lastPos);
//                cout << "i:" << i << "last:" << lastPos << endl;
                if(it != maps.end()) {
                    it->second = i;
                } else{
                    maps.insert(map<char,int>::value_type(s[i],i));
                }

            } else{
                lastPos = it->second;
                it->second = i ;
                cout << "it->second" << it->second << endl;
            }


        }
        return maxAns;
    }
};

#endif //LEETCODE_LONGESTSUBSTRING_H
