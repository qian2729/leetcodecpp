//
// Created by 刘宗前 on 16/4/24.
//

#ifndef LEETCODE_INSERTIONSORT_H
#define LEETCODE_INSERTIONSORT_H


#include <cstdlib>

//efinition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode *curNode = NULL, *pNode = NULL,*lastNode;
        dummy.next = head;
        if (head == NULL || head->next == NULL) return head;
        curNode = head->next;
        lastNode = head;
        while (curNode != NULL){
            ListNode* nextNode = curNode->next;
            pNode = &dummy;
            while (pNode->next->val < curNode->val){
                pNode = pNode->next;
            }
            if(pNode->next != curNode) {
                lastNode->next = curNode->next;
                curNode->next = pNode->next;
                pNode->next = curNode;
            } else{
                lastNode = curNode;
            }
            curNode = nextNode;
        }
        return dummy.next;
    }
};

#endif //LEETCODE_INSERTIONSORT_H
