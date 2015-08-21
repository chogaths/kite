#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;
	int extra = 0;

	while (l1 || l2 || extra) {

		int val = extra;
		if (l1) {
			val += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			val += l2->val;
			l2 = l2->next;
		}

		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = val % 10;
		node->next = NULL;

		extra = val / 10;

		if (!tail) {
			head = tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}

	}

	return head;

}