//
// Created by 刘宗前 on 16/4/30.
//

#ifndef LEETCODE_FINDPATH_H
#define LEETCODE_FINDPATH_H

#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){this->val = val; left = NULL; right = NULL;}
};
void findPathRecusive(const TreeNode *root, int targetNum, int curNum, vector<int>& path);

void findPath(const TreeNode *root, int targetNum){
    if(root == NULL) return ;
    vector<int> path;
    findPathRecusive(root, targetNum, 0, path);
}

void findPathRecusive(const TreeNode *root, int targetNum, int curNum, vector<int>& path){
    if(root == NULL) return;

    curNum += root->val;
    path.push_back(root->val);
    if(root->left == NULL && root->right == NULL && targetNum == curNum){
        vector<int>::iterator begin = path.begin();
        for(;begin != path.end(); ++begin){
            cout << *begin << " ";
        }
        cout << endl;
    }
    if(root->left != NULL){
        findPathRecusive(root->left, targetNum, curNum, path);
    }
    if(root->right != NULL){
        findPathRecusive(root->right, targetNum, curNum, path);
    }
    path.pop_back();
}


#endif //LEETCODE_FINDPATH_H
