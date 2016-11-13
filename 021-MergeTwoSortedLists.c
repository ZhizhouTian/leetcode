struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	struct ListNode* ret = dummy;
	
	struct ListNode* walker1 = l1;
	struct ListNode* walker2 = l2;
	
	while (walker1 != NULL && walker2 != NULL) {
		if (walker1->val < walker2->val) {
			ret->next = walker1;
			walker1 = walker1->next;
		} else {
			ret->next = walker2;
			walker2 = walker2->next;
		}
		ret = ret->next;
	}

	return ret;
}