//
// Created by 刘宗前 on 16/4/26.
//

#ifndef LEETCODE_HEAPSORT_H
#define LEETCODE_HEAPSORT_H

#include <vector>

using namespace std;

void heapSort(vector<int> &data);
void build_max_heap(vector<int> &data);
void swap(vector<int> &data, int i , int j);
void adjust_heap(vector<int> &data, int index, int length);

void heapSort(vector<int> &data){
    build_max_heap(data);
    for(int i = data.size() - 1; i >= 1; --i){
        swap(data, 0, i);
        adjust_heap(data,0,i);
    }
}

void swap(vector<int> &data, int i , int j){
    if(i != j){
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}
void adjust_heap(vector<int> &data, int index, int length){
    int l = index * 2 + 1;
    int r = index * 2 + 2;
    int largest = index;
    if(l < length && data[l] > data[largest]){
        largest = l;
    }
    if(r < length && data[r] > data[largest]){
        largest = r;
    }
    if(largest != index){
        swap(data, largest, index);
        adjust_heap(data, largest,length);
    }
}
void build_max_heap(vector<int> &data){
    for(int i = data.size() / 2 - 1; i >= 0; --i){
        adjust_heap(data, i, data.size());
    }
}



#endif //LEETCODE_HEAPSORT_H
