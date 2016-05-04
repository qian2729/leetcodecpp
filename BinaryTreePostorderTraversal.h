//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_BINARYTREEPOSTORDERTRAVERSAL_H
#define LEETCODE_BINARYTREEPOSTORDERTRAVERSAL_H

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
    vector<int> postorderTraversal(TreeNode* root) {
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
            if (p->left != NULL){
                nodeStack.push(p->left);
            }
            if (p->right != NULL){
                nodeStack.push(p->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

#endif //LEETCODE_BINARYTREEPOSTORDERTRAVERSAL_H
