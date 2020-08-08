/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (44.36%)
 * Likes:    402
 * Dislikes: 0
 * Total Accepted:    79.9K
 * Total Submissions: 180K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续
 * 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int len = nums.size()+1, i = 0, j = 0;
        while(j < nums.size()) {
            while(sum < s && j < nums.size()) { // 避免
                sum += nums[j];
                j++;
            }
            while(sum >= s) {
                sum -= nums[i];
                i++;
            }
            len = min(j-i+1, len);
        }
        if(len == nums.size()+1) return 0;
        return len;
    }
};
// @lc code=end

/*
最小的 连续 子数组
- sum < s
- not find

双指针
    j ->
    while(j < n)
        while(sum < s)
            j++
        while()
            i++

15
[1,2,3,4,5]
*/