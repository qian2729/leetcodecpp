//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_HOUSEROBBERIII_H
#define LEETCODE_HOUSEROBBERIII_H
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
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return ans[0] > ans[1] ? ans[0] : ans[1];
    }
    vector<int> dfs(TreeNode* root){
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(0);
        if (root == NULL){
            return ans;
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        ans[0] = root->val + left[1] + right[1];
        ans[1] = max(left[0],left[1]) + max(right[0],right[1]);
        return ans;
    }
};

#endif //LEETCODE_HOUSEROBBERIII_H
