
//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_UNIQUEBINARYSEARCHTREE_H
#define LEETCODE_UNIQUEBINARYSEARCHTREE_H

#include <vector>
using namespace std;
class Solution {
public:



    int numTrees(int n) {
        int kinds = 0;
        vector<int> dp(n + 1, 1);

        for(int i = 2; i <= n; ++i){
            kinds = 0;
            for (int j = 1; j <= i; ++j){
                kinds += dp[j - 1] * dp[i - j];
            }
            dp[i] = kinds;
        }

        return dp[n];
    }
};

#endif //LEETCODE_UNIQUEBINARYSEARCHTREE_H
