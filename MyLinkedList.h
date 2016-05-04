//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_MYLINKEDLIST_H
#define LEETCODE_MYLINKEDLIST_H
#include <cstdlib>
#include <stack>
#include <iostream>

using namespace std;
struct LinkNode{
    int val;
    LinkNode* next;
    LinkNode(int val) {this->val = val;this->next = NULL};
};

void addToTail(LinkNode **head, int val){
    LinkNode *newNode = new LinkNode(val);

    if(head == NULL){
        *head = newNode;
    } else{
        LinkNode *p = *head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
    }
}

void removeNode(LinkNode ** head, int val){
    if(head == NULL || (*head) == NULL) return;
    LinkNode* p = *head;
    if(p->val == val){
        *head = p->next;
    } else{
        LinkNode * last = p;
        p = p->next;
        while(p){
            LinkNode *next = p->next;
            if(p->val == val){
                last->next = p->next;
            } else{
                last = p;
            }
            delete p;
            p = next;
        }
    }
}

void printLinkList(const LinkNode *head){
    if(head == NULL) return ;
    stack<const LinkNode*> nodeStack;
    while(head != NULL){
        nodeStack.push(head);
        head = head->next;
    }
    while(!nodeStack.empty()){
        cout << nodeStack.top()->val << endl;
        nodeStack.pop();
    }
}


#endif //LEETCODE_MYLINKEDLIST_H
