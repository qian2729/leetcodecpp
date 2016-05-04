//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_BUBBLESORT_H
#define LEETCODE_BUBBLESORT_H

#include <vector>
using namespace std;

void swap(vector<int> &data,int i, int j){
    if(i != j){
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}

void bubbleSort(vector<int> &data){
    for(int i = data.size() - 1;i > 0; --i){
        for(int j = 0; j < i; ++j){
            if(data[j] > data[j + 1]){
                swap(data, j, j + 1);
            }
        }
    }
}


#endif //LEETCODE_BUBBLESORT_H
