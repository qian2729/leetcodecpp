//
// Created by 刘宗前 on 16/5/1.
//

#ifndef LEETCODE_CONVERTBSTTODILINKLIST_H
#define LEETCODE_CONVERTBSTTODILINKLIST_H

#include <cstdlib>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){this->val = val; left = NULL; right = NULL;}
};

TreeNode* convertRecusive(TreeNode*root, TreeNode *& lastNode);

TreeNode* convertBST2DiLinkList(TreeNode *root){
    if(root == NULL) return NULL;
    TreeNode *last = NULL;
    return convertRecusive(root, last);
}

TreeNode* convertRecusive(TreeNode*root, TreeNode *& lastNode){
    if(root == NULL) return NULL;

    if(root->left == NULL && root->right == NULL){
        lastNode = root;
        return root;
    }

    TreeNode *head = root;

    if(root->left != NULL){
        head = convertRecusive(root->left, lastNode);
        root->left = lastNode;
        lastNode->right = root;
    }
    if(root->right != NULL) {
        TreeNode* rHead = convertRecusive(root->right, lastNode);
        root->right = rHead;
        rHead->left = root;
    }
    return head;
}


#endif //LEETCODE_CONVERTBSTTODILINKLIST_H
