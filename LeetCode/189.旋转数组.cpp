/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (42.48%)
 * Likes:    642
 * Dislikes: 0
 * Total Accepted:    149.2K
 * Total Submissions: 351.2K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 说明:
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 要求使用空间复杂度为 O(1) 的 原地 算法。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) { 
        // 1. specail
        if(nums.size() == 1) return;
        k = k%nums.size();

        vector<int> temp;
        int n = nums.size();
        for(int i = n-k; i < n; i++) { //循环 k 次！
            temp.push_back(nums[i]);
        }
        for(int i = n-1; i >= k; i--) {
            nums[i] = nums[i-k];
        }
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
// @lc code=end


/*
1. 直接移动
倒数第 N 个 移动到第 1 个；
倒数第 N-1 个 移动到第 1 个；
...
倒数第 N-k 个 移动到第 1 个；

O(n*k)
class Solution {
public:
    void rotate(vector<int>& nums, int k) { 
        for(int i = 0; i < k; i++) {
            int n = nums.size();
            int temp = nums[n-1];
            for(int j = n-1; j >= 1; j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
    }
};
2. 额外数组
一次搬运
*/