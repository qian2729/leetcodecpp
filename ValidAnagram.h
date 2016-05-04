//
// Created by 刘宗前 on 16/4/24.
//

#ifndef LEETCODE_VALIDANAGRAM_H
#define LEETCODE_VALIDANAGRAM_H
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> charMap;
        for(int i = 0; i < s.size(); ++i){
            map<char,int>::iterator it = charMap.find(s[i]);
            if(it == charMap.end()){
                charMap.insert(map<char,int>::value_type(s[i],1));
            } else {
                it->second += 1;
            }
        }
        for(int i = 0; i < t.size(); ++i){
            map<char,int>::iterator it = charMap.find(t[i]);
            if(it == charMap.end()){
                return false;
            }
            it->second -= 1;
        }
        for(map<char,int>::iterator begin = charMap.begin(); begin < charMap.end(); ++begin){
            if (begin->second != 0){
                return false;
            }
        }
        return true;
    }

};

#endif //LEETCODE_VALIDANAGRAM_H
