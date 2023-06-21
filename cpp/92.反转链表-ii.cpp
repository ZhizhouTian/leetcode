/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.67%)
 * Likes:    1579
 * Dislikes: 0
 * Total Accepted:    404.1K
 * Total Submissions: 725.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *tmp;
        int sum = 0;
        ListNode ret(0), *l = &ret, *r = &ret;

        /* 1. check args */
        tmp = head;
        while (tmp) {
            tmp = tmp->next;
            sum++;
        }

        if (left <= 0 || left > right || right > sum)
            return head;

        /* 2. join to the return list */
        int index = 1;
        tmp = head;
        while (tmp) {
            ListNode *node = tmp;
            tmp = tmp->next;

            if (index < left) {
                /* l works */
                l->next = node;
                l = l->next;
            } else if (left <= index && index <= right) {
                /* l works */
                node->next = l->next;
                l->next = node;
                if (index == left)
                    r = node;
            } else {
                /* r works */
                r->next = node;
                r = r->next;
            }
            index++;
        }
        r->next = NULL;

        return ret.next;
    }
};
// @lc code=end

