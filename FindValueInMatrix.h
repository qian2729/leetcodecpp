//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_FINDVALUEINMATRIX_H
#define LEETCODE_FINDVALUEINMATRIX_H
#include <vector>
using namespace std;

bool hasNumber(vector<vector<int>> matrix, int val){
    bool found = false;

    if(matrix.size() > 0){
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, right = n - 1;

        while(top < m && right >= 0){
            if(matrix[top][right] == val){
                found = true;
                break;
            }
            else if(matrix[top][right] < val){
                ++top;
            } else{
                -- right;
            }
        }
    }

    return found;

}

#endif //LEETCODE_FINDVALUEINMATRIX_H
