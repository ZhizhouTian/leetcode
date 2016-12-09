#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* pa = headA;
	struct ListNode* pb = headB;
	unsigned int la = 0;
	unsigned int lb = 0;

	if (headA == NULL || headB == NULL)
		return NULL;

	while (pa != NULL) {
		la ++;
		pa = pa->next;
	}

	while (pb != NULL) {
		lb ++;
		pb = pb->next;
	}

	pa = headA;
	pb = headB;

	if (la > lb) {
		int delta = la - lb;
		while (delta-- > 0)
			pa = pa->next;
	} else {
		int delta = lb - la;
		while (delta-- > 0)
			pb = pb->next;
	}

	while (pa && pb && pa->val != pb->val) {
		pa = pa->next;
		pb = pb->next;
	}

	return pa;
}
