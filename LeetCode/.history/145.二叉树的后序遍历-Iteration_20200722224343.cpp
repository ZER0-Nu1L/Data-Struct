/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (71.88%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    98.5K
 * Total Submissions: 136.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return;

        vector<int> result;
        stack<TreeNode*> st;
        stack<TreeNode*> st_inv;
        st.push(root);
        while(!st.empty()) {
            root = st.top();
            st_inv.push(root);
            st.pop();
            if(root->left) st.push(root->left);
            if(root->right) st.push(root->right);
        }
        while(!st_inv.empty()) {
            result.push_back(st_inv.top()->val);
            st_inv.pop();
        }
        return result;
    }
};
// @lc code=end

