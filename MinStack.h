//
// Created by 刘宗前 on 16/4/30.
//

#ifndef LEETCODE_MINSTACK_H
#define LEETCODE_MINSTACK_H

#include <cstdlib>
#include <stack>

using namespace std;

template <typename T> class MinStack{
public:
    MinStack(){};
    ~MinStack();
    void push(const T& val);
    T top();
    void pop();
    T min();
private:
    stack<T> pushStack;
    stack<T> minStack;
};

template <typename T>void  MinStack::push(const T& val){
    pushStack.push(val);
    if(minStack.empty() || val < minStack.top()){
        minStack.push(val);
    }
    else{
        minStack.push(minStack.top());
    }
}
template <typename T> T MinStack::top(){
    if(pushStack.empty()){
        throw new exception();
    }
    return pushStack.top();
}
template <typename T> MinStack::pop(){
    if(pushStack.empty()){
        throw new exception();
    }
    pushStack.pop();
    minStack.pop();
}
template <typename T> T MinStack::min(){
    if(minStack.empty()){
        throw new exception();
    }
    return minStack.top();
}




#endif //LEETCODE_MINSTACK_H
