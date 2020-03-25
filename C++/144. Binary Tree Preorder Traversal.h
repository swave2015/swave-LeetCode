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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            res.push_back(node->val);
            if(node->right) {
                stack.push(node->right);
            }
            if(node->left) {
                stack.push(node->left);
            }
        }

        return res;
    }
};