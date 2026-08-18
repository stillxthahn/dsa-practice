/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root, 0);
        return res;
    }

    int helper(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        int leftSubTree = max(helper(root->left, sum + root->val), 0);
        int rightSubTree = max(helper(root->right, sum + root->val), 0);

        res = max(res, root->val + rightSubTree + leftSubTree);
        int maxSubTree = max(leftSubTree, rightSubTree);
        return root->val + maxSubTree;
    }
};
