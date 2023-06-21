/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode *addToTail(ListNode *header, int val) {
        ListNode *newnode = new ListNode(val);
        header->next = newnode;
        return header;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode tmpRetListHeader, *retListHeader = &tmpRetListHeader;

        for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
            int result = l1->val + l2->val + flag;
            flag = result / 10;
            addToTail(retListHeader, result % 10);
            retListHeader = retListHeader->next;
        }

        for (; l1; l1 = l1->next) {
            int result = l1->val + flag;
            flag = result / 10;
            addToTail(retListHeader, result % 10);
            retListHeader = retListHeader->next;
        }

        for (; l2; l2 = l2->next) {
            int result = l2->val + flag;
            flag = result / 10;
            addToTail(retListHeader, result % 10);
            retListHeader = retListHeader->next;
        }

        if (flag) {
            addToTail(retListHeader, flag);
            retListHeader = retListHeader->next;
        }

        return tmpRetListHeader.next;
    }
};
// @lc code=end

