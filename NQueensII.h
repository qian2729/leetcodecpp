//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_NQUEENSII_H
#define LEETCODE_NQUEENSII_H

#include <vector>
#include <cstdlib>
class Solution {
public:
    int totalNQueens(int n) {
        std::vector<int> mark(n, 0);
        int ans = 0;
        backtracking(mark, n, 0, ans);
        return ans;
    }
    bool isValid(std::vector<int> mark, int row, int col){
        for (int r = 0; r < row; ++r){
            if (mark[r] == col || abs(row - r) == abs(col - mark[r])){
                return false;
            }
        }
        return true;
    }
    void backtracking(std::vector<int> mark, int n, int row, int &ans){
        if (row == n){
            ans ++;
        }
        for (int c = 0; c < n; ++c){
            if (isValid(mark, row, c)){
                mark[row] = c;
                backtracking(mark, n, row + 1, ans);
            }
        }
    }

};

#endif //LEETCODE_NQUEENSII_H
