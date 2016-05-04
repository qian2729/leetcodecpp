//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_SAMETREE_H
#define LEETCODE_SAMETREE_H


#include <cstdlib>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){};
};
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        if (p == NULL && q == NULL){
            return true;
        }
        queue<TreeNode*> pQueue;
        queue<TreeNode*> qQueue;
        TreeNode* pNode;
        TreeNode* qNode;
        if (p != NULL) {pQueue.push(p);}
        if (q != NULL) {qQueue.push(q);}
        while (!pQueue.empty() && (pQueue.size() == qQueue.size())){
            pNode = pQueue.front(); pQueue.pop();
            qNode = qQueue.front(); qQueue.pop();
            if (pNode->val != qNode->val) {return false;}

            if (pNode->left != NULL && qNode->left != NULL) {
                pQueue.push(pNode->left);
                qQueue.push(qNode->right);
            }
            else if(pNode->left == NULL && qNode->left == NULL){}
            else{
                return false;
            }
            if (pNode->right != NULL && qNode->right != NULL) {
                pQueue.push(pNode->right);
                qQueue.push(qNode->left);
            }
            else if(pNode->right == NULL && qNode->right == NULL){}
            else{
                return false;
            }
        }
        return pQueue.size() == qQueue.size();
    }
    bool isSameTree_recusive(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL){
            return true;
        }
        if (p != NULL && q != NULL && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
        }
        return false;
    }
};

#endif //LEETCODE_SAMETREE_H
