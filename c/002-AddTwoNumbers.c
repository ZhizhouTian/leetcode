/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* ret = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* pl1 = l1;
    struct ListNode* pl2 = l2;
    int carry = 0;

    if (pl1 && pl2) {
	struct ListNode* temp = malloc(sizeof(struct ListNode));
        if (temp == NULL)
	    goto no_mem;
	temp->val = (pl1->val + pl2->val) % 10;
	carry = !!((pl1->val + pl2->val) / 10);
	ret = temp;
	pl1 = pl1->next;
	pl2 = pl2->next;
	prev = ret;
    }

    while (pl1 && pl2) {
        struct ListNode* temp = malloc(sizeof(struct ListNode));
        if (temp == NULL)
            goto no_mem;
        temp->val = (pl1->val + pl2->val + carry) % 10;
	carry = !!((pl1->val + pl2->val + carry) / 10);
	prev->next = temp;
        prev = prev->next;

        pl1 = pl1->next;
        pl2 = pl2->next;
    }

    while (pl1) {
	struct ListNode* temp = malloc(sizeof(struct ListNode));
	if (temp == NULL)
            goto no_mem;
	temp->val = (pl1->val + carry) % 10;
	carry = !!((pl1->val + carry) / 10);
	prev->next = temp;
	prev = prev->next;

	pl1 = pl1->next;
    }

    while (pl2) {
	struct ListNode* temp = malloc(sizeof(struct ListNode));
	if (temp == NULL)
            goto no_mem;
	temp->val = (pl2->val + carry) % 10;
	carry = !!((pl2->val + carry) / 10);
	prev->next = temp;
	prev = prev->next;

	pl2 = pl2->next;
    }

    if (carry) {
	struct ListNode* temp = malloc(sizeof(struct ListNode));
	if (temp == NULL)
            goto no_mem;
	temp->val = carry;
	prev->next = temp;
	prev = prev->next;
    }

    prev->next = NULL;

    return ret;
no_mem:
    while(ret) {
	struct ListNode* next = ret->next;
        free(ret);
        ret = next;
    }
    return NULL;
}
