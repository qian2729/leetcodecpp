//
// Created by 刘宗前 on 16/4/25.
//

#ifndef LEETCODE_CONSTRUCTBINARYTREE_H
#define LEETCODE_CONSTRUCTBINARYTREE_H

#include <cstdlib>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    typedef vector<int>::iterator iter;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildRecusive(inorder.begin(),inorder.end(),postorder.begin(), postorder.end());
    }
    TreeNode* buildRecusive(iter ibegin, iter iend,iter pbegin, iter pend){
        if(pbegin == pend) return NULL;
        int val = *(pend - 1);
        TreeNode *root = new TreeNode(val);
        iter mid;
        for(mid = ibegin; (*mid) != val; ++mid);
        root->left = buildRecusive(ibegin,mid,pbegin,pbegin + (mid-ibegin));
        root->right = buildRecusive(mid + 1,iend,pbegin + (mid - ibegin),pend - 1);
        return root;
    }

};

#endif //LEETCODE_CONSTRUCTBINARYTREE_H
