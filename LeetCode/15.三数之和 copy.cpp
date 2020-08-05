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
        if(nums.size()<3) return ans;
        if(count(nums.begin(), nums.end(), 0) >= 3 )
            ans.push_back({0, 0, 0});
        // 1. sort
        sort(nums.begin(), nums.end());
        if(nums[0]>0) return ans;
        if(nums[nums.size()-1]<0) return ans;
        // 2. double pointer
        int i = 0;
        while(i < nums.size() && nums[i]<0){
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                if(nums[i] + nums[r] + nums[l] > 0)
                    r--;
                else if(nums[i] + nums[r] + nums[l] < 0)
                    l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1])
                        l++;
                    while(l < r && nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }
            // 避免nums[i]作为第一个数重复出现
            while(i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
            i++;
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
    Output: [-1, 0, 1],[-1, 0, 1],[-1, -1, 2] x
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