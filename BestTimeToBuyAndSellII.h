//
// Created by 刘宗前 on 16/4/22.
//

#ifndef LEETCODE_BESTTIMETOBUYANDSELLII_H
#define LEETCODE_BESTTIMETOBUYANDSELLII_H
#include <vector>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 1){
            return 0;
        }
        int profit = 0;
        for(size_t i = 1; i < prices.size(); ++i){
            if (prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};

#endif //LEETCODE_BESTTIMETOBUYANDSELLII_H
