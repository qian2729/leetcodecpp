//
// Created by 刘宗前 on 16/4/30.
//

#ifndef LEETCODE_CLONECOMPLEXLINKLIST_H
#define LEETCODE_CLONECOMPLEXLINKLIST_H

#include <cstdlib>

struct ComplexLinkNode{
    int val;
    ComplexLinkNode *next;
    ComplexLinkNode *sibling;
    ComplexLinkNode(int val){this->val = val;next = NULL; sibling = NULL;}
};

ComplexLinkNode * splitLinkList(ComplexLinkNode *head{
    if(head == NULL) return NULL;
    ComplexLinkNode *newHead = head->next;
    ComplexLinkNode *p = head->next->next;
    ComplexLinkNode *q = newHead;
    head->next = q->next;
    while (p!= NULL){
        q->next = p->next;
        p->next = q->next;
        q = q->next;
        p = p->next;
    }
    return newHead;
}

void modifySiblingPointer(ComplexLinkNode *head){
    if(head == NULL) return ;
    ComplexLinkNode *p;
    while(p){
        if(p->sibling != NULL){
            p->next->sibling = p->sibling->next;
        }
        p = p->next->next;
    }
}

void clone(ComplexLinkNode *head){
    if(head == NULL) return;
    ComplexLinkNode *p = head;
    while(p != NULL){
        ComplexLinkNode *newNode = new ComplexLinkNode(p->val);
        newNode->next = p->next;
        p->next = newNode;
        p = newNode->next;
    }
}


ComplexLinkNode* cloneLinkList(ComplexLinkNode *head){
    if(head == NULL) return NULL;
    clone(head);
    modifySiblingPointer(head);
    return splitLinkList(head);
}


#endif //LEETCODE_CLONECOMPLEXLINKLIST_H
