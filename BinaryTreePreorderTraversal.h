//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_BINARYTREEPREORDERTRAVERAL_H
#define LEETCODE_BINARYTREEPREORDERTRAVERAL_H

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> nodeStack;
        TreeNode *p;
        if (root == NULL){
            return ans;
        }
        nodeStack.push(root);
        while (!nodeStack.empty()){
            p = nodeStack.top(); nodeStack.pop();
            ans.push_back(p->val);
            if(p->right){
                nodeStack.push(p->right);
            }
            if(p->left){
                nodeStack.push(p->left);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_BINARYTREEPREORDERTRAVERAL_H
