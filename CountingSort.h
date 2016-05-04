//
// Created by 刘宗前 on 16/4/28.
//

#ifndef LEETCODE_COUNTINGSORT_H
#define LEETCODE_COUNTINGSORT_H

#include <vector>

using namespace std;
int maxInVector(const vector<int> &data);

vector<int> countingSort(vector<int> &data){
    vector<int> ans(data.size());
    if (data.size() <= 1) return ans;

    int maxVal = maxInVector(data);
    vector<int> c(maxVal + 1,0);

    for(int i = 0; i < data.size(); ++i){
        ++c[data[i]];
    }
    for(int i = 1; i < c.size(); ++i){
        c[i] += c[i-1];
    }
    for(int i = data.size() - 1; i >= 0; --i){
        ans[c[data[i]] - 1] = data[i];
        --c[data[i]];
    }
    return ans;
}

int maxInVector(const vector<int> &data){
    int maxVal = INT32_MIN;
    for(int i = 0; i < data.size(); ++i){
        maxVal = max(maxVal, data[i]);
    }
    return maxVal;
}

#endif //LEETCODE_COUNTINGSORT_H
