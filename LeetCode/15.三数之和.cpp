/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (28.88%)
 * Likes:    2453
 * Dislikes: 0
 * Total Accepted:    293.3K
 * Total Submissions: 1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // 0. special
        if(nums.size() < 3) return ans;
        if(count(nums.begin(), nums.end(), 0) >= 3 )
            ans.push_back({0, 0, 0});
        // 1. sort
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return ans;
        if(nums[nums.size()-1] < 0) return ans;
        // 2. HashMap
        map<int, int> HashMap;
        map<int, int> flag;
        // vector<int> alnums;
        for(int i = 0; i < nums.size(); i++) {
            if(HashMap.count(nums[i]) > 0) {
                flag[nums[i]] = 1;
                continue;
            }
            flag[nums[i]] = 0;
            HashMap[nums[i]] = i; // 记入的是最后一个的 [1,1,-2] HashMap[1] = 2
        }
        // 3. double pointer
        for(int i = 0; nums[i] < 0; i++) {
            if(i != 0)
                if(nums[i] == nums[i-1])
                    continue;
            for(int j = nums.size()-1; nums[j] > 0; j--) {
                if(j != nums.size()-1)
                    if(nums[j] == nums[j+1])
                        continue;
                if(HashMap.count(-(nums[i]+nums[j])) > 0) {
                    int k = HashMap[-(nums[i]+nums[j])];
                    if(flag[-(nums[i]+nums[j])] & i == k) {
                        k++;
                    }
                    // if(k != i && k != j)
                    if(k > i && k < j)
                        ans.push_back({nums[i], -(nums[i]+nums[j]), nums[j]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
- 有点像 target = i + j
1. 排序+双指针
    sort() n*log(n)
    Input: [-1, 0, 1, 2, -1, -4]，
    Output: [-1, 0, 1],[-1, 0, 1],[-1, -1, 2] xxxxxxxxxxx
2. 
if(k > i && k < j)  

算法流程：
1. 特判：数组长度；全+或全-
2. 排序
3. 建哈希表（为查找 k） | 这里的坑是，重复元素的处理
4. 循环遍历
    1. 处理重复问题：跳过，避免出现重复解
    2. 由 i, j 求 k，重复元素处理

[0, 0, 0]
[1,1,-2]
[-1,0,1,2,-1,-4]
[-4,-2,-1]
*/