//
// Created by 刘宗前 on 16/4/30.
//

#ifndef LEETCODE_VERIFYSEQUENCEOFBST_H
#define LEETCODE_VERIFYSEQUENCEOFBST_H

#include <cstdlib>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){this->val = val; left = NULL; right = NULL;}
};

bool verifyBSTPostOrder(int sequence[], int length){
    if(sequence == NULL || length <= 0)
        return false;
    int rootVal = sequence[length - 1];
    int i = 0;
    for(; i < length && sequence[i] < rootVal; ++i){}
    int j = i;
    for(;j < length; ++j){
        if(sequence[j] < rootVal)
            return false;
    }
    bool left = true;
    if(i > 0)
        left = verifyBSTPostOrder(sequence, i);
    bool right = true;
    if(j < length)
        right = verifyBSTPostOrder(sequence + i, length - i - 1);
    return left && right;
}


#endif //LEETCODE_VERIFYSEQUENCEOFBST_H
