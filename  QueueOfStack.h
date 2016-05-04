//
// Created by 刘宗前 on 16/4/29.
//

#ifndef LEETCODE_QUEUEOFSTACK_H
#define LEETCODE_QUEUEOFSTACK_H
#include <stack>

using namespace std;
template <typename T> class CQueue{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T &node){
    stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead(){
    T ans;
    if(stack2.empty()){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if(!stack2.empty()){
        ans = stack2.top();
        stack2.pop();
    } else{
        throw new std::exception();
    }
    return ans;
}





#endif //LEETCODE_QUEUEOFSTACK_H
