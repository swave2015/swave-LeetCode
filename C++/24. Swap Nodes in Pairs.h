#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        p->next = head;
        while(p->next != NULL && p->next->next != NULL) {
            ListNode* node1 = p->next;
            ListNode* node2 = p->next->next;
            node1->next = node2->next;
            node2->next = node1;
            p->next = node2;
            p = node1;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
    }
};