#include "Solution.cpp"
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
        vector<ListNode *> num;
        ListNode a;
        a.val=1;
        ListNode a2;
        a2.val=2;
        ListNode a3;
        a3.val=3;
        ListNode b1;
        b1.val=1;
        ListNode b2;
        b2.val=3;
        ListNode b3;
        b3.val=4;
        ListNode c1;
        c1.val=2;
        ListNode c2;
        c2.val=6;
        a.next=&a2;
        a2.next=&a3;
        a3.next=NULL;
        b1.next=&b2;
        b2.next=&b3;
        b3.next=NULL;
        c1.next=&c2;
        c2.next=NULL;
        num.push_back(&a);
        num.push_back(&b1);
        num.push_back(&c1);
        Solution s;
        s.mergeKLists(num);
}