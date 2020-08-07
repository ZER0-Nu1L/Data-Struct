/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (56.68%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    47.1K
 * Total Submissions: 83.2K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j = 0, i = 0;
        int flag = 0;
        int sum = 0;
        // 1. specail
        if(!nums.size()) return 0;
        // 2. mark and sum
        for(; j < nums.size(); j++) {
            if(nums[j] == 1) {
                if(!flag) {
                    i = j;
                    flag = 1;
                }
            } else if( nums[j] != 1 && flag) {
                sum = max(sum, j-i);
                flag = 0;
            }
        }
        if(flag) sum = max(sum, j-i);
        return sum;
    }
};
// @lc code=end

// 很典型的双指针应用
// [1], [0], [0,0,1]