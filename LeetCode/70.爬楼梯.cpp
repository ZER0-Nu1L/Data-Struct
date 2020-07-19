/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (49.99%)
 * Likes:    1129
 * Dislikes: 0
 * Total Accepted:    241.3K
 * Total Submissions: 482.5K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// f(1) = 1
// f(2) = 2
// f(3) = f(1)+f(2) | 3 的第一步可能走一格，也可能走两格
// f(4) = f(3)+f(2)

// f(n) = f(n-1) + f(n-2)

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
    if(n>=6)  return 2*climbStairs(n-4)+3*climbStairs(n-3);
    else if(n<=1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 3;
    else if(n==4) return 5;
    else  return 8;

    }
};

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n == 1) return 1;
//         else if(n == 2) return 2;
//         else return climbStairs(n-1) + climbStairs(n-2);
//     }   // 傻递归 超时了……
// };
// @lc code=end

