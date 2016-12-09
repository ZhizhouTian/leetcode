#include <stdio.h>

/*
 * 虽然在网上的解法中，并没有使用n变量而简洁了一些，但是在C语言中，
 * 常常要在循环删除及释放某个节点，此时n变量就是必要的
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode dummy;
	struct ListNode* pos;
	struct ListNode* n;
	struct ListNode* prev;

	if (head == NULL)
		return NULL;

	dummy.next = head;
	prev = &dummy;
	pos = head;
	n = pos->next;

	for(; pos!=NULL; pos=n, n=n->next) {
		if (pos->val == val)
			prev->next = n;
		else
			prev = pos;
		if (n == NULL)
			break;
	}

	return dummy.next;
}
