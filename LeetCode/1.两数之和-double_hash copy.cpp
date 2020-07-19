/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (46.84%)
 * Likes:    6587
 * Dislikes: 0
 * Total Accepted:    620.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> result;
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> HashMap;
        // 1. set up HashMap
        for(int i = 0; i < nums.size(); i++) {
            HashMap[nums[i]] = i;
        }
        // 2. find
        for(int i = 0; i < nums.size(); i++) {
            if(HashMap.count(target-nums[i])>0 && i != HashMap[target-nums[i]]) {
                result.push_back(i);
                result.push_back(HashMap[target - nums[i]]);
                return result;
            }
        }
        return result;
    }
};
// @lc code=end

