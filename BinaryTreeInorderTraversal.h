//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_BINARYTREEINORDERTRAVERAL_H
#define LEETCODE_BINARYTREEINORDERTRAVERAL_H

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> nodeStack;
        TreeNode *p;

        if (root == NULL){
            return ans;
        }
        p = root;
        while (p != NULL || !nodeStack.empty()){
            if (p != NULL){
                nodeStack.push(p);
                p = p->left;
            } else{
                p = nodeStack.top(); nodeStack.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_BINARYTREEINORDERTRAVERAL_H
