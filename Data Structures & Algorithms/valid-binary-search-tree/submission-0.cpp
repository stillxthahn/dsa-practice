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
using ll = long long;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        ll left = LLONG_MIN;
        ll right = LLONG_MAX;
        return helper(root, left, right);
    }

    bool helper(TreeNode* root, ll left, ll right) {
        if (root == nullptr) return true;

        if (root->val > left && root->val < right) {
            return helper(root->left, left, root->val) && helper(root->right, root->val, right);
        }
        return false;
    }
};
