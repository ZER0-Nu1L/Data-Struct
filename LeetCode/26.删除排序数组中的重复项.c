/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除排序数组中的重复项
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (50.80%)
 * Likes:    1524
 * Dislikes: 0
 * Total Accepted:    361.4K
 * Total Submissions: 711.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 给定数组 nums = [1,1,2], 
 * 
 * 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
 * 
 * 你不需要考虑数组中超出新长度后面的元素。
 * 
 * 示例 2:
 * 
 * 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 * 
 * 你不需要考虑数组中超出新长度后面的元素。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 为什么返回数值是整数，但输出的答案是数组呢?
 * 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 * 你可以想象内部操作如下:
 * // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 * int len = removeDuplicates(nums);
 * 
 * // 在函数里修改输入数组对于调用者是可见的。
 * // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 * 
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize)
{
    int time = 0;
    for(int i = 0; i < numsSize - 1; i++) {
        time = 1;   //代表一个元素出现的次数
        for(int j = i+1; j < numsSize; j++) {
            if(nums[i] == nums[j]) {
                time++;
            } else {
                break;
            }
        }
        // time 次出现，需要移动 time-1 格，~~移动次数 = 后面的个数 = numsSize-i-time-1~~
        if(time > 1) {
            // numsSize = xxx + j + time - 1
            for(int j = i+1; j < numsSize-time+1; j++) {
                nums[j] = nums[j+time-1];
            }
        }
        numsSize = numsSize - time + 1;
    }
    return numsSize;
}


// @lc code=end

//1. for i for j  if == move? 
// 优化：对重复个数进行计数——一次性移动