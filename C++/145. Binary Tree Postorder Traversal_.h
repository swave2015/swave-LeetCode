#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<int> output;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            output.push(node->val);
            if(node->left) {
                stack.push(node->left);
            }
            if(node->right) {
                stack.push(node->right);
            }
        }
        while(!output.empty()) {
            res.push_back(output.top());
            output.pop();
        }

        return res;
    }
};