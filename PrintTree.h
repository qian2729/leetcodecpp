//
// Created by 刘宗前 on 16/4/30.
//

#ifndef LEETCODE_PRINTTREE_H
#define LEETCODE_PRINTTREE_H

#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){this->val = val;left = NULL; right = NULL;}
};

void printTree(const TreeNode *root){
    if(root == NULL) return;

    queue<const TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while(!nodeQueue.empty()){
        const TreeNode *r = nodeQueue.front();
        nodeQueue.pop();
        cout << r->val << endl;
        if(r->left)
            nodeQueue.push(r->left);
        if(r->right)
            nodeQueue.push(r->right);

    }
}


#endif //LEETCODE_PRINTTREE_H
