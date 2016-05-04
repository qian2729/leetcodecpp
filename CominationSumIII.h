//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_COMINATIONSUMIII_H
#define LEETCODE_COMINATIONSUMIII_H
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        backtracking(k, n, 1, 0, t, ans );
        return ans;
    }
    void backtracking(int k, int n,int low, int sum, vector<int> val, vector<vector<int>>& ans){
        if (k == 0 && sum == n){
            ans.push_back(val);
            return;
        }
        if (sum > n || 10 - low < k) return;
        for (int i = low; i <= 9; ++i){
            val.push_back(i);
            backtracking(k - 1, n, i + 1, sum + i, val, ans);
            val.pop_back();
        }
    }
};

#endif //LEETCODE_COMINATIONSUMIII_H
