#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL) {
            return;
        } else if (node->next == NULL) {
            delete node;
            node = NULL;
            return;
        }
        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = delNode->next;
        delete delNode;

        return;
    }
};