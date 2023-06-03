#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode dummy = {0};
	struct ListNode* p = NULL;
	struct ListNode* walker = head;
	struct ListNode* n = NULL;

	while (walker != NULL) {
		n = walker->next;
		p = dummy.next;
		dummy.next = walker;
		walker->next = p;
		walker = n;
	}

	return dummy.next;
}

int main(void)
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	struct ListNode* ret = reverseList(head);
	return 0;
}
