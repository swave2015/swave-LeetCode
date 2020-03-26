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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        while(root != NULL || !stack.empty()) {
            if(root != NULL) {
                stack.push(root);
                root = root->left;
            } else {
                root = stack.top();
                stack.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }

        return res;
    }
};