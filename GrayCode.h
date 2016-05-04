//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_GRAYCODE_H
#define LEETCODE_GRAYCODE_H
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int size = 1 << n;
        ans.push_back(0);
        for (int i = 1; i < size; ++i){
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};

#endif //LEETCODE_GRAYCODE_H
