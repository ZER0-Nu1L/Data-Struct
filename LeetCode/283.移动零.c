/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (61.56%)
 * Likes:    645
 * Dislikes: 0
 * Total Accepted:    172.9K
 * Total Submissions: 280.8K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start


void moveZeroes(int* nums, int numsSize) {
    int num_0 = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) {
            num_0++;
        }
    }
    for(int i = 0; i < numsSize; i++) {
        if(num_0 == 0)
            break;
        if(nums[i] == 0) {
            for(int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j+1];
            }
            i--;
            nums[numsSize-1]=0;
            num_0 --;
        }
    }
}
// @lc code=end

// 思路：
// 1. for, if zero, move
// 2. new array, put | 题目说明中不建议
// 3. index
// 4. for if 0, count; for if not 0,move

// [0, 0, 0, 0]
// []

// 官方，选择性看；看看别人的代码；

// move 之后，原来的位置重新遇到，这个问题没有办法解决
// i-- 的话，到后面全是0的部分就会跳不出来 - 死掉
// 不要抢救！换思路！

// 五毒，之后看英文 & 题解 most vote