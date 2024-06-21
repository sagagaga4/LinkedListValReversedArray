struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

  struct ListNode *dummyHead =
      (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *current = dummyHead;
  int carry = 0;

  while (l1 != NULL || l2 != NULL || carry > 0) {
    int sum = carry;

    if (l1 != NULL) {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2 != NULL) {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;
    sum = sum % 10;

    struct ListNode *newNode =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = sum;
    newNode->next = NULL;

    current->next = newNode;
    current = newNode;
  }

  struct ListNode *result = dummyHead->next;
  free(dummyHead); // Free the dummy head node

  return result;
}

// Utility function to create a new ListNode with a given value
struct ListNode *createNode(int val) {
  struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = NULL;
  return node;
}

// Utility function to print a linked list
void printList(struct ListNode *head) {
  struct ListNode *current = head;
  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->next;
  }
  printf("NULL\n");
}