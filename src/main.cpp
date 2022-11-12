#include "../include/Greedy/Solution.hpp"
#include "../include/Tree/Tree.hpp"
#include "../include/DP/DP.hpp"
#include "../include/LinkList/LinkList.hpp"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
        ListNode a;
        ListNode b;
        ListNode c;
        ListNode d;
        ListNode e;
        ListNode f;
        ListNode l;
        a.val=1;a.next=&b;
        b.val=2;b.next=&c;
        c.val=3;c.next=&d;
        d.val=4;d.next=&e;
        e.val=5;e.next=&f;
        f.val=6;f.next=NULL;

        LinkList solution;
        ListNode *tem= solution.reverseKGroup(&a,2);
}