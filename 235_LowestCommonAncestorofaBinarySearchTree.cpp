/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /* Recursive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val>p->val && root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val && root->val<q->val)
            return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
    */
    //Iterative
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* curr= root;
        while(true)
        {
            if(curr->val>p->val && curr->val>q->val)
                curr=curr->left;
            else if(curr->val<p->val && curr->val<q->val)
                curr=curr->right;
            else
                break;
        }
        return curr;
    }  
};
