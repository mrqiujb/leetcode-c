struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL || l2==NULL) return NULL;
    struct ListNode *head=l1;
    struct ListNode *l2pre=l2;
    int count=0;
    while(l1->next!=NULL && l2->next!=NULL)
    {
        l1->val=l1->val+l2->val;
        l1=l1->next;
        l2=l2->next;
        count++;
    }
    l1->val=l1->val+l2->val;
    while (count>0) {
        struct ListNode *tem=l2pre;
        l2pre=l2pre->next;
        free(tem);
        count--;
    }
    if(l2->next!=NULL)
    {
        l1->next=l2->next;
    }
    //进位
    struct ListNode *add=head;
    int cf=0;
    struct ListNode *end=head;
    while (add->next!=NULL) {
        add->val=add->val+cf;
        if(add->val>9)
        {
            cf=add->val/10;
            add->val=add->val%10;
        }
        else {
            cf=0;
        }
        add=add->next;
    }
    add->val=add->val+cf;
     if(add->val>9)
     {
        cf=add->val/10;
        add->val=add->val%10;
     }
     else {
            cf=0;
     }
    if(cf!=0)
    {
        struct ListNode *tem=(struct ListNode*)malloc(sizeof(struct ListNode));
        tem->next=NULL;
        tem->val=cf;
        add->next=tem;
    }
    return head;
}