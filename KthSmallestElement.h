//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_KTHSMALLESTELEMENT_H
#define LEETCODE_KTHSMALLESTELEMENT_H

#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    int leftCount;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){};
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int kth = 0;
        stack<TreeNode*> nodeStack;
        TreeNode *p;

        if (root == NULL || k < 1){
            return ans;
        }
        p = root;
        while(p != NULL || !nodeStack.empty()){
            if (kth == k){
                break;
            }
            if (p != NULL){
                nodeStack.push(p);
                p = p->left;
            }
            else{
                p = nodeStack.top(); nodeStack.pop();
                kth += 1;
                ans = p->val;
                p = p->right;
            }
        }
        return ans;
    }

    void insert(TreeNode** root, int val){
        TreeNode *node = new TreeNode(val);
        TreeNode *p = NULL;
        TreeNode *cur = NULL;
        if (root == NULL){
            *root = node;
            return;
        }
        cur = *root;
        while (cur != NULL && cur->val != val){
            p = cur;
            if (cur->val < val){
                cur = cur->right;
            }
            else{
                cur = cur->left;
                cur->leftCount += 1;
            }
            cur = cur->val < val ? cur->right : cur->left;
        }
        if(cur == NULL){
            if (p->val < val){
                p->right = node;
            }
            else{
                p->left = node;
            }
        }
    }
    void remove(TreeNode** root, TreeNode* node){

    }
};

#endif //LEETCODE_KTHSMALLESTELEMENT_H
