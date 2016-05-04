//
// Created by 刘宗前 on 16/5/1.
//

#ifndef LEETCODE_REVERSEPAIR_H
#define LEETCODE_REVERSEPAIR_H

#include <vector>
using namespace std;

int mergeCount(vector<int> &nums, int start, int mid, int end){
    vector<int> tmp(end - start + 1);

    int i = mid;
    int j = end;
    int count = 0;
    int index = end - start;
    while(i >= start && j > mid){
        if(nums[i] > nums[j]){
            tmp[index --] = nums[i--];
            count += j - mid;
        } else {
            tmp[index--] = nums[j--];
        }
    }
    while(i >= start) tmp[index--] = nums[i--];
    while(j > mid) tmp[index--] = nums[j--] ;
    for(size_t i = 0;i < tmp.size(); ++i){
        nums[start + i] = tmp[i];
    }
    return count;
}

int merge(vector<int> &nums, int start, int end){
    if(start >= end) return 0;

    int mid = (start + end) >> 1;
    int left = merge(nums, start,mid);
    int right = merge(nums, mid + 1, end);
    int count = mergeCount(nums,start, mid, end);

    return left + right + count;
}


int count(vector<int> A, int n){

    return merge(A, 0, n - 1);
}





#endif //LEETCODE_REVERSEPAIR_H
