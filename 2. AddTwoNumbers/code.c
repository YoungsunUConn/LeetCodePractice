/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* curr = NULL;
    struct ListNode* head = NULL;

    
    int add = 0;
    while (!(l1 == NULL && l2 == NULL)) {
        int l1_val = 0;
        int l2_val = 0;
        int tmp_add;
        struct ListNode* ret_next = (struct ListNode*)malloc(sizeof(struct ListNode));
        

        if(l1 != NULL) l1_val = l1->val;
        if(l2 != NULL) l2_val = l2->val;


        tmp_add = (int)((l1_val + l2_val + add) / 10);
        ret_next->val = (l1_val + l2_val + add) % 10;
        ret_next->next = NULL;

        if( head == NULL) {
            head = ret_next;
            curr = ret_next;
        } 
        else {
            
            curr->next = ret_next;
            curr = curr->next;
        }

        add = tmp_add;
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
        
        
    } 

    if (add > 0) {
        struct ListNode* ret_final = (struct ListNode*)malloc(sizeof(struct ListNode));
        

        ret_final->val = add;
        ret_final->next = NULL;
        curr->next = ret_final;
    }
    return head;
        
}
