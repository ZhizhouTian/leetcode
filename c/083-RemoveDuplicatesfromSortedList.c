#include <stdio.h>

struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode dummy;
	struct ListNode* prev;
	struct ListNode* pos;
	struct ListNode* n;

	if (head == NULL)
		return NULL;

	dummy.next = head;
	prev = &dummy;
	pos = head;
	n = pos->next;

	while (pos != NULL && n != NULL) {
		if (pos->val == n->val)
			prev->next = n;
		else
			prev = pos;
		pos = n;
		n = n->next;
	}

	return dummy.next;
}
