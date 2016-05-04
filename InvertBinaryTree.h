//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_INVERTBINARYTREE_H
#define LEETCODE_INVERTBINARYTREE_H

#include <cstdlib>
#include <queue>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode * root){
        if (root == NULL){
            return root;
        }
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        TreeNode *p;
        TreeNode *left;
        TreeNode *right;
        while(!node_queue.empty()){
            p = node_queue.front(); node_queue.pop();
            left = p->left; right = p->right;
            p->left = right;
            p->right = left;
            if (left != NULL){
                node_queue.push(left);
            }
            if (right != NULL){
                node_queue.push(right);
            }
        }
        return root;
    }
    TreeNode* invertTree_recusive(TreeNode* root) {
        if (root == NULL){
            return NULL;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->right = invertTree(left);
        root->left = invertTree(right);
        return root;
    }
};

#endif //LEETCODE_INVERTBINARYTREE_H
