//
// Created by 刘宗前 on 16/4/24.
//

#ifndef LEETCODE_MAXSQUARE_H
#define LEETCODE_MAXSQUARE_H
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int ans = 0;
        if (m == 0) return 0;
        int n = matrix[0].size();
        int row, col;
        int rowCount, colCount;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = matrix[0][j] == '1' ? 1: 0;
        }
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if(matrix[i][j] == '1'){
                    row = i - 1, rowCount = 0;
                    while (row >= (i - dp[i-1][j-1]) && matrix[row][j] == '1'){
                        rowCount ++;
                        --row;
                    }
                    col = j - 1, colCount = 0;
                    while (col >= (j - dp[i-1][j-1]) && matrix[i][col] == '1'){
                        colCount ++;
                        --col;
                    }
                    int tmp = min(rowCount, colCount) + 1;
                    dp[i][j] = tmp;
                    ans = max(ans, tmp * tmp );
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODE_MAXSQUARE_H
