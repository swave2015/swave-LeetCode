#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};


struct NodeInfo {
    TreeNode* node;
    bool canVisitVal;
    NodeInfo(TreeNode* node, bool canVisitVal): node(node), canVisitVal(canVisitVal) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<NodeInfo> stack;
        stack.push(NodeInfo(root, false));
        while(!stack.empty()) {
            NodeInfo info = stack.top();
            stack.pop();
            if(info.canVisitVal) {
                res.push_back(info.node->val);
            } else {
                info.canVisitVal = true;
                stack.push(info);
                if(info.node->right) {
                    stack.push(NodeInfo(info.node->right, false));
                }
                if(info.node->left) {
                    stack.push(NodeInfo(info.node->left, false));
                }
            }
        }

        return res;
    }
};
