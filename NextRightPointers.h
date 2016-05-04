//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_NEXTRIGHTPOINTERS_H
#define LEETCODE_NEXTRIGHTPOINTERS_H

#include <cstdlib>
//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return ;
        }
        recusive(root, NULL);
    }
    void recusive(TreeLinkNode *root, TreeLinkNode* sub){
        if (root->left != NULL && root->right != NULL){
            root->left->next = root->right;
        }
        if (sub != NULL && sub->left != NULL){
            root->right->next = sub->left;
        }
        if (root->left != NULL){
            recusive(root->left, root->right);
        }
        if (root->right != NULL) {
            recusive(root->right, sub != NULL ? sub->left : NULL);
        }
    }
};


#endif //LEETCODE_NEXTRIGHTPOINTERS_H
