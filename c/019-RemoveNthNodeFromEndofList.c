struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	dummy->next = head;
	
	struct ListNode* walker = dummy->next;
	int length = 0;
	
	while (walker != NULL) {
		length++;
		walker = walker->next;
	}
	
	if (n<0 || n>length) {
		free(dummy);
		return head;
	}
	
	walker = dummy;
	
	int i;
	for (i=0; i<length-n; i++) {
		walker = walker->next;
	}
	
	struct ListNode* temp = walker->next;
	walker->next = walker->next->next;
	free(temp);
	
	struct ListNode* ret = dummy->next;
	free(dummy);
	return ret;
}