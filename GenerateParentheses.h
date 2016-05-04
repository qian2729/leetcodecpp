//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_GENERATEPARENTHESES_H
#define LEETCODE_GENERATEPARENTHESES_H
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(n, n, "", ans);
        return ans;
    }
    void backtracking( int left, int right, string val, vector<string> &ans){
        if (right < left){
            return;
        }
        if (right == 0 && left == 0){
            ans.push_back(val);
            return;
        }
        if(left > 0){
            backtracking(left - 1, right, val + '(', ans);
        }
        if(right > 0){
            backtracking(left, right - 1, val + ')', ans);
        }
    }
};

#endif //LEETCODE_GENERATEPARENTHESES_H
