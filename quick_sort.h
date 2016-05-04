//
// Created by 刘宗前 on 16/4/22.
//

#ifndef LEETCODE_QUICK_SORT_H
#define LEETCODE_QUICK_SORT_H

#include <cstdlib>
#include <ctime>

int random(int low, int high){
    srand((unsigned)time(0));
    return low + (rand() % (high - low + 1));
}
void swap(int *p, int a, int b){
    if (a != b){
        int tmp = p[a];
        p[a] = p[b];
        p[b] = tmp;
    }
}
int partition(int *p, int low, int high){
    int pivot = p[high];
    int i = low - 1;
    for (int j = low; j < high; ++j){
        if (p[j] <= pivot){
            swap(p, j, ++i);
        }
    }
    swap(p, ++i,high);
    return i;
}
int rand_partition(int *p, int low, int high){
    swap(p, high, random(low,high));
    return partition(p, low, high);
}

void random_sort(int *p, int low, int high){
    if (low < high){
        int m = rand_partition(p, low, high);
        random_sort(p, low, m - 1);
        random_sort(p, m + 1, high);
    }
}

void quick_sort(int *p, int n){
    random_sort(p, 0, n - 1);
}

#endif //LEETCODE_QUICK_SORT_H
