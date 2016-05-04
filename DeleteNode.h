//
// Created by 刘宗前 on 16/4/29.
//

#ifndef LEETCODE_DELETENODE_H
#define LEETCODE_DELETENODE_H
#include <cstdlib>
struct LinkNode{
    int val;
    LinkNode *next;
    LinkNode(int val){this->val = val; next = NULL};
};

void deleteNode(LinkNode **head, LinkNode *deleteNode){
    if(head == NULL || deleteNode == NULL){
        return;
    }

    if(deleteNode->next != NULL){
        LinkNode *next = deleteNode->next;
        deleteNode->val = next->val;
        deleteNode->next = next->next;
        delete next;
    } else if(*head == deleteNode){
        delete deleteNode;
        deleteNode = NULL;
        *head = NULL;
    } else{
        LinkNode *p = *head;
        while(p->next != deleteNode){
            p = p->next;
        }
        p->next = NULL;
        delete deleteNode;
        deleteNode = NULL;
    }
}

#endif //LEETCODE_DELETENODE_H
