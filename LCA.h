//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_LCA_H
#define LEETCODE_LCA_H
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL){
            return NULL;
        }
        if (p->val > q->val){
            return lowestCommonAncestor(root, q, p);
        }
        if(p->val <= root->val && q->val >= root->val){
            return root;
        }
        return p->val > root->val ? lowestCommonAncestor(root->right, p, q) : lowestCommonAncestor(root->left, p, q);
    }
};

#endif //LEETCODE_LCA_H
