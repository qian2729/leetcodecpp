//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
#define LEETCODE_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H

#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedRecusive(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedRecusive(vector<int>& nums, int begin, int end){
        TreeNode* root;
        int mid;
        if(begin > end){
            return NULL;
        }
        mid = (end + begin) / 2;
        cout << "begin" << begin << "mid" << mid << "end" << end << endl;
        root = new TreeNode(nums[mid]);
//        cout << root->val << endl;
        root->left = sortedRecusive(nums, begin, mid - 1);
        root->right = sortedRecusive(nums, mid + 1, end);
        return root;
    }
};


#endif //LEETCODE_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
