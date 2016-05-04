//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_MAXIMUMDEPTHOFBINARYTREE_H
#define LEETCODE_MAXIMUMDEPTHOFBINARYTREE_H

#include <cstdlib>
#include <queue>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
public:
    int maxDepth_recursive(const TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
    int maxDepth(const TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int level = 0;
        int level_num = 1;
        int next_level_num = 0;
        const TreeNode * p;
        queue<const TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()){
            p = node_queue.front();
            node_queue.pop();
            --level_num;
            if (p->left != NULL){
                node_queue.push(p->left);
                next_level_num += 1;
            }
            if (p->right != NULL){
                node_queue.push(p->right);
                next_level_num += 1;
            }
            if (level_num == 0){
                level_num = next_level_num;
                next_level_num = 0;
                level += 1;
            }
        }

        return level;
    }
};


#endif //LEETCODE_MAXIMUMDEPTHOFBINARYTREE_H
