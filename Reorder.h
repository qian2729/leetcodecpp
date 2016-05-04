//
// Created by 刘宗前 on 16/4/29.
//

#ifndef LEETCODE_REORDER_H
#define LEETCODE_REORDER_H

#include <cstdlib>

void reorder(int *array, int length, bool (*fun)(int)){
    if(array == NULL || length <= 0) return ;

    int *begin = array;
    int *end = array + length - 1;

    while(begin < end){
        while(begin < end && !fun(*begin)){
            ++begin;
        }
        while(end > begin && fun(*begin)){
            --end;
        }
        if(begin < end){
            int tmp = *begin;
            *begin = *end;
            *end = tmp;
        }
    }
}



bool isEven(int n){
    return (n & 0x1) == 0;
}

void oddEvenReorder(int *array, int length){
    reorder(array, length, isEven);
}


#endif //LEETCODE_REORDER_H
