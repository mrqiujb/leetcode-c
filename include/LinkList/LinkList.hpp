
#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

#include <utility>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ;
class LinkList
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    ListNode* swapPairs(ListNode* head);
    ListNode* Reverse(ListNode * head,int n);
    ListNode* reverseKGroup(ListNode* head, int k);
    ListNode* rotateRight(ListNode *head, int k);
};

#endif
