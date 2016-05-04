//
// Created by 刘宗前 on 16/5/1.
//

#ifndef LEETCODE_DUPLICATECOUNT_H
#define LEETCODE_DUPLICATECOUNT_H

#include <vector>
using namespace std;

int findFirst(const vector<int> nums,int target){
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    int ans = -1;

    while(low <= high){
        mid = (low + high) >> 1;
        if(nums[mid] == target){
            if(mid == low || (nums[mid - 1] != target)) {
                ans = mid;
                break;
            }
        } else if(nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int findLast(const vector<int> nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    int ans = -1;

    while(low <= high){
        mid = (low + high) >> 1;
        if(nums[mid] == target){
            if(mid == high || nums[mid + 1] != target){
                ans = mid;
                break;
            }
        }else if(nums[mid] < target){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return ans;
}

int duplicateCount(const vector<int> nums, int target){
    if(nums.size() <= 1) return 0;
    int first = findFirst(nums, target);
    int last = findLast(nums,target);
    if(first != -1 && last != -1)
        return last - first + 1;
    return -1;
}


#endif //LEETCODE_DUPLICATECOUNT_H
