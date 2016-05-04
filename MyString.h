//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_MYSTRING_H
#define LEETCODE_MYSTRING_H
#include <cstdlib>
#include <cstring>

class MyString{
    MyString(){

    }

    MyString& operator =(const MyString &str){
        if(&str != this){
            MyString tmp(str);
            char* p = tmp.p_data;
            tmp.p_data = p_data;
            p_data = p;
        }
        return *this;
    }

private:
    char *p_data;
};


#endif //LEETCODE_MYSTRING_H
