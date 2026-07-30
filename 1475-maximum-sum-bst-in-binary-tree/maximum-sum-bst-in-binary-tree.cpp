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
class NodeInfo {
public:
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
    NodeInfo(bool is_bst, int min_v, int max_v, int s)
        : isBST(is_bst), minVal(min_v), maxVal(max_v), sum(s) {}
};

class Solution {
private:
    int maxSum = 0;
    NodeInfo traverse(TreeNode* root) {
        if (!root) {
            return NodeInfo(true, INT_MAX, INT_MIN, 0);
        }
        NodeInfo left = traverse(root->left);
        NodeInfo right = traverse(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currentSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currentSum);

            int currentMin = min(root->val, left.minVal);
            int currentMax = max(root->val, right.maxVal);
            return NodeInfo(true, currentMin, currentMax, currentSum);
        }
        return NodeInfo(false, 0, 0, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        traverse(root);
        return maxSum;
    }
};