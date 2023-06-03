#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode dummy;
	struct ListNode* ret = &dummy;

	struct ListNode* walker1 = l1;
	struct ListNode* walker2 = l2;

	while (walker1 != NULL && walker2 != NULL) {
		ret->next = malloc(sizeof(struct ListNode));
		memset(ret->next, 0, sizeof(struct ListNode));

		if (walker1->val < walker2->val) {
			ret->next->val = walker1->val;
			walker1 = walker1->next;
		} else {
			ret->next->val = walker2->val;
			walker2 = walker2->next;
		}

		ret = ret->next;
	}

	while (walker1 != NULL) {
		ret->next = malloc(sizeof(struct ListNode));
		memset(ret->next, 0, sizeof(struct ListNode));

		ret->next->val = walker1->val;
		ret = ret->next;
		walker1 = walker1->next;
	}

	while (walker2 != NULL) {
		ret->next = malloc(sizeof(struct ListNode));
		memset(ret->next, 0, sizeof(struct ListNode));

		ret->next->val = walker2->val;
		ret = ret->next;
		walker2 = walker2->next;
	}

	return dummy.next;
}

int main(void)
{
	struct ListNode l1;
	struct ListNode *pl2;

	l1.val = 1;
	l1.next = NULL;

	struct ListNode *ret = mergeTwoLists(&l1, pl2);

	while(ret) {
		printf("%d", ret->val);
		ret = ret->next;
	}
	return 0;
}
