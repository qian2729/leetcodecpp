//
// Created by 刘宗前 on 16/4/24.
//

#ifndef LEETCODE_EDITDISTANCE_H
#define LEETCODE_EDITDISTANCE_H
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t size1 = word1.size();
        size_t size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for (size_t i = 1; i <= size1; ++i){
            dp[i][0] = i;
        }
        for (size_t j = 1; j <= size2; ++j){
            dp[0][j] = j;
        }
        for(size_t i = 1; i <= size1; ++i){
            for(int j = 1; j <= size2; ++j){
                if(word1[i - 1] == word2[j-1]){
                    cout << word1 << "\t" << word2 << endl;
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[size1][size2];
    }
};



#endif //LEETCODE_EDITDISTANCE_H
