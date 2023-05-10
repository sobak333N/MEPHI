void createNode(struct ListNode **head, struct ListNode **last, int r)
 {
    struct ListNode *new = NULL;
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->next = NULL;
    new->val = r;

    if(*head == NULL)
    {
        *head = new;
        *last = new;
    }
    else
    {
        (*last)->next =new;
        *last = new;
    }
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

   struct ListNode* head = NULL;
   struct ListNode* last = NULL;
   struct ListNode* temp = NULL;
   int sum = 0;
   int rem = 0;

   while(l1 && l2)
   {
       sum = sum + l1->val + l2->val;
       rem = sum % 10;
       sum = sum /10;
       l1 = l1->next;
       l2 = l2->next;
       createNode(&head, &last, rem);
   }
    temp = (l1==NULL? l2 : l1);
    while(temp)
    {
        sum = sum +temp->val;
        rem = sum % 10;
        sum = sum / 10;
        temp = temp->next;
        createNode(&head, &last, rem);
    }
    if(sum)
    {
        createNode(&head, &last, sum);
    }
    return head;
}