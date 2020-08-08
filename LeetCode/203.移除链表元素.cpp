/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (45.97%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    94.1K
 * Total Submissions: 204.6K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            if(cur->val == val) {
                if(cur == head) {
                    ListNode* temp = cur;
                    cur = cur->next;
                    delete temp;
                    head = cur;
                } else {
                    pre->next = cur->next;
                    ListNode* temp = cur;
                    cur = cur->next;
                    delete temp;
                }
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

