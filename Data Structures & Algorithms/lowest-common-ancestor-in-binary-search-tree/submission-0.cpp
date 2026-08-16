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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root > p and root < q
        if (root == nullptr || root->val == p->val || root->val == q->val ) {
            return root;
        }
        TreeNode *leftSubTree = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightSubTree = lowestCommonAncestor(root->right, p, q);

        if (leftSubTree && rightSubTree) {
            return root;
        }
        return leftSubTree ? leftSubTree : rightSubTree;
    }
};
