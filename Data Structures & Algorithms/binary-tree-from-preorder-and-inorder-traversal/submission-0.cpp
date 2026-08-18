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
    int curIdx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i; 
        }
        return helper(preorder, mp, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, unordered_map<int, int> &mp, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[curIdx++]; 
        TreeNode* root = new TreeNode(rootVal);

        root->left = helper(preorder, mp, start, mp[rootVal] - 1);
        root->right = helper(preorder, mp, mp[rootVal] + 1, end);
        return root;
    }
};
