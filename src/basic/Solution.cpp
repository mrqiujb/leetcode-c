/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <algorithm>

using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        vector<ListNode*> tem_res;
        while (lists.size()!=1)
        {
            int i=0;
            while(i+1<lists.size())
            {
                ListNode *first=lists[i],*second=lists[i+1];
                tem_res.push_back(MergeList(first,second));
                i+=2;
            }
            if(i+1==lists.size()) tem_res.push_back(lists[i]);
            lists.clear();
            lists=tem_res;
            tem_res.clear();   
        }
        return lists[0];
    }
    ListNode* MergeList(ListNode *first,ListNode *second)
    {
        if(first==NULL)return second;
        if(second==NULL) return first;
        ListNode *res=NULL;
        if(first->val>second->val)
        {
            res=second;
            second=second->next;
        }
        else
        {
            res=first;
            first=first->next;
        }
        ListNode *k=res,*i=first,*j=second;
        while (i!=NULL&&j!=NULL)
        {
            if(i->val>j->val)
            {
                k->next=j;
                k=k->next;
                j=j->next;
            }
            else
            {
                k->next=i;
                k=k->next;
                i=i->next;
            }
        }
        if(i!=NULL)
        {
            k->next=i;
        }
        if(j!=NULL)
        {
            k->next=j;
        }
        return res;
    }
    
};