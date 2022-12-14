#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        vector<int>dp(nums.size() + 1,0);
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];//dp[i] 表示nums[0...i] 能得到的最长时间
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            //遍历迄今为止的最大值，两种情况取较大：
            //1：预约本次，则上一次不预约（dp[i-2] + nums[i]）
            //2：本次不预约，则值为预约到上一次的最大值
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
