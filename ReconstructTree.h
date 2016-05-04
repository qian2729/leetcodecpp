//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_RECONSTRUCTTREE_H
#define LEETCODE_RECONSTRUCTTREE_H

#include <cstdlib>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){this->val = val; left = NULL; right = NULL:}
};
typedef vector<int>::const_iterator  VecIter;
TreeNode* recusive(VecIter pStart, VecIter pEnd, VecIter iStart, VecIter iEnd);

TreeNode* reconstruct(const vector<int> preOrder, const vector<int> inOrder){
    if(preOrder.size() == 0 || preOrder.size() != inOrder.size()) return NULL;

    return recusive(preOrder.begin(), preOrder.end(), inOrder.begin(),inOrder.end());
}
TreeNode* recusive(VecIter pStart, VecIter pEnd, VecIter iStart, VecIter iEnd){
    if(pStart == pEnd) return NULL;
    TreeNode *root = new TreeNode(*pStart);
    VecIter imid = find(iStart, iEnd, *pStart);
    if(imid == iEnd){
        throw std::exception();
    }
    root->left = recusive(pStart + 1, pStart + 1 +  (imid - iStart), iStart,imid );
    root->right = recusive(pStart + 1 +  (imid - iStart),pEnd,imid + 1, iEnd);
    return root;
}

int find(const vector<int> order, int val){
    for(int i = 0; i < order.size(); ++i){
        if(order[i] == val){
            return i;
        }
    }
    return -1;
}


#endif //LEETCODE_RECONSTRUCTTREE_H
