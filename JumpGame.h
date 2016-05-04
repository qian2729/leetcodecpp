//
// Created by 刘宗前 on 16/4/22.
//

#ifndef LEETCODE_JUMPGAME_H
#define LEETCODE_JUMPGAME_H

#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (max_pos < i){
                return false;
            }
            max_pos = max(max_pos,nums[i] + i);
        }

        return true;

    }
};

#endif //LEETCODE_JUMPGAME_H
