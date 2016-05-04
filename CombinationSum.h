//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_COMBINATIONSUM_H
#define LEETCODE_COMBINATIONSUM_H
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates,target,0, 0, v, ans);
        return ans;
    }
    void backtracking(vector<int> &candidates, int target, int start, int sum,  vector<int> val, vector<vector<int>>& ans){
        if (target == sum){
            ans.push_back(val);
            return;
        }
        if (target < sum) return;
        for(int i = start; i < candidates.size(); ++i){
            val.push_back(candidates[i]);
            backtracking(candidates, target, i, candidates[i] + sum,val, ans);
            val.pop_back();
        }
    }
};

#endif //LEETCODE_COMBINATIONSUM_H
