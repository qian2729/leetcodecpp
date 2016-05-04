//
// Created by 刘宗前 on 16/4/23.
//

#ifndef LEETCODE_BURSTBOLLONS_H
#define LEETCODE_BURSTBOLLONS_H
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n;
        int r;

        vector<int> new_num;

        new_num.push_back(1);
        for(int i = 0; i < nums.size(); ++i){
            new_num.push_back(nums[i]);
        }
        new_num.push_back(1);
        n = new_num.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for (int range = 2; range < n; ++ range){
            for (int l = 0; l < n - range; ++l){
                r = l + range;
                for (int m = l + 1; m < r; ++m){
                    dp[l][r] = max(dp[l][r], dp[l][m] + new_num[l] * new_num[m] * new_num[r] + dp[m][r]);
                    cout << l << "\t" << r << "\t" << dp[l][r]  << endl;
                }
            }
        }
        return dp[0][n-1];
    }
};

#endif //LEETCODE_BURSTBOLLONS_H
