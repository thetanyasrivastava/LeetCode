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
    int d;
    int diameterOfBinaryTree(TreeNode* root) {
        d=0;
        int h = getHeight(root,d);
        return d;
    }
    
    int getHeight(TreeNode* root,int &d)
    {
        if(!root)
            return 0;
        
        int lh=getHeight(root->left,d);
        int rh=getHeight(root->right,d);
        
        if(lh+rh>d)
            d=lh+rh;
        
        return 1+max(lh,rh);
    }
};
