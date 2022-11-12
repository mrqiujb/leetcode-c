#include "../../include/LinkList/LinkList.hpp"

ListNode *LinkList::removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return NULL;
    ListNode *j = head;
    for (int i = 0; i < n; i++)
    {
        if (j == NULL)
        {
            return head;
        }
        j = j->next;
    }
    ListNode *p = head->next;
    ListNode *pre = head;
    if (j == NULL)
        return head->next;
    j = j->next;

    while (j != NULL)
    {
        j = j->next;
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    return head;
}
ListNode *LinkList::mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *i = list1, *j = list2;
    ListNode *res;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (i->val > j->val)
    {
        res = j;
        j = j->next;
    }
    else
    {
        res = i;
        i = i->next;
    }
    ListNode *ans = res;
    while (i != NULL && j != NULL)
    {
        if (i->val > j->val)
        {
            res->next = j;
            res = res->next;
            j = j->next;
        }
        else
        {
            res->next = i;
            res = res->next;
            i = i->next;
        }
    }
    if (i != NULL)
    {
        while (i != NULL)
        {
            res->next = i;
            res = res->next;
            i = i->next;
        }
    }
    else if (j != NULL)
    {
        while (j != NULL)
        {
            res->next = j;
            res = res->next;
            j = j->next;
        }
    }
    return ans;
}
ListNode *LinkList::swapPairs(ListNode *head)
{
    if (head == NULL)
        return NULL; // no element
    ListNode *i = head->next, *pre = head;
    if (i == NULL)
        return head;
    //先手动完成一次交换
    ListNode *tem = i->next;
    i->next = pre;
    pre->next = tem;
    ListNode *ans = i;
    if (tem == NULL)
        return ans;
    i = tem->next;
    while (i != NULL) // less two element
    {
        ListNode *isub1 = pre->next;
        ListNode *iadd1 = i->next;
        i->next = isub1;
        isub1->next = iadd1;
        pre->next = i;
        pre = isub1;
        if (iadd1 == NULL)
            return ans;
        i = iadd1->next;
    }
    return ans;
}

// return last element point
ListNode *LinkList::Reverse(ListNode *head, int n)
{
    ListNode *pre = head;
    if (pre == NULL)
        return NULL; //只有一个元素
    int i = 0;
    ListNode *p = pre->next;
    ListNode *tem = p->next;
    while (p != NULL && i < n - 1)
    {
        // if(tem==NULL) return NULL; //元素总数小于n 返回null
        p->next = pre;
        pre = p;
        p = tem;
        i++;
        if (tem != NULL)
            tem = p->next;
    }
    head->next = p;
    return pre;
}

ListNode *LinkList::reverseKGroup(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
        return head;
    ListNode *p = head;
    ListNode *pre = head;
    int i = 0;
    while (p != NULL && i < k)
    {
        p = p->next;
        i++;
    }
    if (i != k)
        return head;
    ListNode *ans = Reverse(pre, k);
    while (p != NULL)
    {
        i = 0;
        ListNode *n = p;
        while (p != NULL && i < k)
        {
            p = p->next;
            i++;
        }
        if (i != k)
            return ans;
        ListNode *tem = Reverse(n, k);
        pre->next = tem;
        pre = n;
    }
    return ans;
}

ListNode *LinkList::rotateRight(ListNode *head, int k)
{
    int count = 0;
    ListNode *p = head;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    if (count == 0 || k == 0)
        return head;

    int n = k % count; //执行k次
    int i = 0;
    p = head;
    while (i < (count - n - 1))
    {
        p = p->next;
        i++;
    }
    ListNode *pre = p->next, *ans = p->next;
    if (pre == NULL)
        return head;
    while (pre->next != NULL)
        pre = pre->next;
    pre->next = head;
    p->next = NULL;
    return ans;
}