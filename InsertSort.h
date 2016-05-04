//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_INSERTSORT_H
#define LEETCODE_INSERTSORT_H
#include <vector>

using namespace std;

void insertionSort(vector<int> &data){
    for(int i = 1; i < data.size(); ++i){
        int tmp = data[i];
        int index = i;
        for(;index > 0; --index){
            if(data[index - 1] < tmp){
                break;
            }
            data[index] = data[index - 1];
        }
        data[index] = tmp;
    }
}


#endif //LEETCODE_INSERTSORT_H
