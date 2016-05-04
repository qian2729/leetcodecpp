//
// Created by 刘宗前 on 16/4/22.
//

#ifndef LEETCODE_GASSTATION_H
#define LEETCODE_GASSTATION_H

#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (sum(gas) < sum(cost)){
            return -1;
        }
        int startPos = 0;
        int gasCount = 0;

        for (int i = 0; i < gas.size(); ++i){
            gasCount += gas[i];
            if (gasCount < cost[i]){
                startPos = i + 1;
                gasCount = 0;
            } else{
                gasCount -= cost[i];
            }
        }
        return startPos;
    }
    int sum(vector<int>& vec){
        int total = 0;
        for (vector<int>::iterator begin = vec.begin();begin < vec.end();++begin){
            total += *begin;
        }
        return total;
    }
};

#endif //LEETCODE_GASSTATION_H
