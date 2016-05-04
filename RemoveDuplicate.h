//
// Created by 刘宗前 on 16/4/25.
//

#ifndef LEETCODE_REMOVEDUPLICATE_H
#define LEETCODE_REMOVEDUPLICATE_H

#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newLength = nums.size();
        int count = 0;
        int last = INT32_MIN;
        int left = 0;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != last){
                nums[left++] = nums[i];
                count == 1;
            } else{
                count ++;
                if(count <= 2){
                    nums[left++] = nums[i];
                } else{
                    --newLength;
                }
            }
            last = nums[i];
        }
        return newLength;
    }
};

#endif //LEETCODE_REMOVEDUPLICATE_H
