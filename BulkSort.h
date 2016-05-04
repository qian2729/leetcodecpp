//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_BULKSORT_H
#define LEETCODE_BULKSORT_H
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int>::iterator Iter_Vec_Int;
vector<int> bulkSort(vector<int>& array);
void findMinAndMax(vector<int>& array, int &minVal, int &maxVal);
void insert(vector<int> &array, int val);

vector<int> bulkSort(vector<int>& array){
    int maxVal = INT32_MAX, minVal = INT32_MIN;
    findMinAndMax(array, minVal, maxVal);
    int arrange = maxVal - minVal + 1;
    int bulkCount = sqrt(arrange);
    int bulkSize = ceil(float(arrange) / bulkCount);
    vector<vector<int>> bulks(bulkCount);
    vector<int> ans;
    for(int i = 0; i < array.size(); ++i){
        insert(bulks[(array[i] - minVal) / bulkSize], array[i]);
    }
    for(int i = 0; i < bulks.size(); ++i){
        for(int j = 0; j < bulks[i].size(); ++j){
            ans.push_back(bulks[i][j]);
        }
    }
    return ans;
}

void insert(vector<int> &array, int val){
    array.push_back(val);
    Iter_Vec_Int iter = array.end() - 1;
    for(;iter != array.begin(); --iter){
        if(*(iter - 1) > val){
            *iter = *(iter - 1);
        } else{
            break;
        }
    }
    *iter = val;
}

void findMinAndMax(vector<int>& array, int &minVal, int &maxVal){
    minVal = INT32_MAX;
    maxVal = INT32_MIN;
    for(int i = 0; i < array.size(); i += 2){
        if(i + 1 < array.size()){
            if(array[i] < array[i + 1]){
                maxVal = max(maxVal, array[i+1]);
                minVal = min(minVal, array[i]);
            } else{
                maxVal = max(maxVal, array[i]);
                minVal = min(minVal, array[i+1]);
            }
        } else{
            maxVal = max(maxVal, array[i]);
            minVal = min(minVal, array[i]);
        }
    }
}



#endif //LEETCODE_BULKSORT_H
