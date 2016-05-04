//
// Created by 刘宗前 on 16/4/22.
//

#ifndef LEETCODE_JUMPGAMEII_H
#define LEETCODE_JUMPGAMEII_H
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int last = 0, cur_max = 0, ans = 0;

        for (int i = 0; i < nums.size(); ++i){
            if (i > last){
                last = cur_max;
                ans += 1;
            }
            cur_max = max(cur_max, nums[i] + i);
        }
        return ans;
    }
};

#endif //LEETCODE_JUMPGAMEII_H
