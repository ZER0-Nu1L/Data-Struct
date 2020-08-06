/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 *
 * https://leetcode-cn.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (41.54%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 50.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 输出:  [1,2,4,7,5,3,6,8,9]
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 给定矩阵中的元素总数不会超过 100000 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        //
        int flag = 1, i = 0, j = 0;

        vector<int> ans;
        // 1. special
        int n = matrix.size();
        if(n == 0) return ans;
        int m = matrix[0].size();
        if(m == 0) return ans;
        if(n == 1 && m == 1) {
            ans.push_back(matrix[0][0]);
            return ans;
        }
        // 2. work
        while(1) {
            if(flag) {
                while(i >= 0 && j < m) {
                    ans.push_back(matrix[i--][j++]);
                }
                if(i == n-2 && j == m)
                    break;
                if (j == m) {
                    i++;
                    j--;
                }
                i++;
                flag = 0;
            } else {
                while(j >= 0 && i < n) {
                    ans.push_back(matrix[i++][j--]);
                }
                if(i == n && j == m-2)
                    break;
                if (i == n) {
                    i--;
                    j++;
                }
                j++;
                flag = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
规律：
    i-1, j+1
    i+1, j-1
    int flag = 1;
    while(i <= matrix.size()-1 && j <= matrix.size()-1) {
        if(flag) P

    }
*/