//
// Created by 刘宗前 on 16/4/22.
//

#ifndef LEETCODE_PATCHINGARRAY_H
#define LEETCODE_PATCHINGARRAY_H

#include <vector>
using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int index = 0;
        long total = 1;
        int ans = 0;
        while (total <= n){
            if (index < nums.size() && nums[index] <= total) {
                total += nums[index];
                index += 1;
            } else{
                total <<= 1;
                ans += 1;
                cout << total << endl;
            }
        }
        return ans;
    }
};


#endif //LEETCODE_PATCHINGARRAY_H
