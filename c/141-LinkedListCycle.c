bool hasCycle(struct ListNode *head) {
	if (head == NULL)
		return false;
	struct ListNode* walker = head;
	struct ListNode* runner = head;
	
	while (runner->next != NULL && runner->next->next != NULL) {
		walker = walker->next;
		runner = runner->next->next;
		if (walker == runner)
			return true;
	}
	
	return false;
}