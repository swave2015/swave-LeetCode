#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        int res = findSum(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);

        return res;
    }

private:
    int findSum(TreeNode* node, int sum) {
        int res = 0;
        if (node == NULL) {
            return 0;
        }
        if (node->val == sum) {
            res++;
        }
        res += findSum(node->left, sum - node->val);
        res += findSum(node->right, sum - node->val);

        return res;
    }
};