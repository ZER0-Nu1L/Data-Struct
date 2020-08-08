/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.55%)
 * Likes:    1204
 * Dislikes: 0
 * Total Accepted:    329.5K
 * Total Submissions: 854.2K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size() == 0) return ans;
        // 1. length min
        int min_len = INT_MAX;
        for(int i = 0; i < strs.size(); i++) 
            min_len = min(min_len, (int)strs[i].size());
        // 2. circle cmp
        bool flag = false;
        for(int i = 0; i < min_len; i++) {
            for(int j = 0; j < strs.size()-1; j++) {
                if(strs[j][i] != strs[j+1][i]) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            ans += strs[0][i];
        }
        return ans;
    }
};
// @lc code=end

