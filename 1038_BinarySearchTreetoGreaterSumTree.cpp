//This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return root;
        int sum=0;
        greater(root,sum);
        return root;
    }
    void greater(TreeNode* root,int &sum)
    {
        if(!root) return;
        greater(root->right,sum);
        
        sum+=root->val;
        root->val=sum;
        
        greater(root->left,sum);
    
    }
};
