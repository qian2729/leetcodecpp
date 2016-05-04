//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_REPLACE_SPACE_H
#define LEETCODE_REPLACE_SPACE_H
#include <vector>

using namespace std;

void replaceSpace(char* str, int n){
    if (str == NULL || n <= 0) return ;
    int new_n = 0;
    int origin_n = 0;

    for(int i = 0;str[i] != '\0'; ++i){
        new_n += str[i] == ' ' ? 3 : 1;
        origin_n ++;
    }
    if(new_n > n) return;
    str[new_n] = '\0';
    int p2 = new_n - 1;

    for(int p1 = origin_n - 1; p1 >= 0; --p1){
        if(str[p1] == ' ') {
            str[p2--] = str[p1];
        } else{
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
        }
    }

}


#endif //LEETCODE_REPLACE_SPACE_H
