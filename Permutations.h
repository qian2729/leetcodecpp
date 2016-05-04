//
// Created by 刘宗前 on 16/5/1.
//

#ifndef LEETCODE_PERMUTATIONS_H
#define LEETCODE_PERMUTATIONS_H

#include <vector>
#include <cstdlib>
using namespace std;

typedef vector<int>::iterator VecIter;

void swap(VecIter a, VecIter b){
    if(a != b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void permutationRecusive(VecIter begin, VecIter end, vector<int> val, vector<vector<int>>& ans){
    if(begin == end){
        ans.push_back(val);
        return;
    }
    for(VecIter iter = begin;iter != end;++iter){
        swap(begin, iter);
        val.push_back(*begin);
        permutationRecusive(begin + 1,end, val, ans);
        swap(begin, iter);
        val.pop_back();
    }
}

vector<vector<int>> permute(vector<int> nums){

    vector<int> val;
    vector<vector<int>> ans;
    if(nums.size() == 0) return ans;
    permutationRecusive(nums.begin(),nums.end(), val, ans);
    return ans;
}



#endif //LEETCODE_PERMUTATIONS_H
