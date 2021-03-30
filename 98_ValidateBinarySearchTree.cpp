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
   /* Method 1 
   bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);
 }
    
    bool validate(TreeNode* root,long l,long r)
    {
        if(!root) return true;
        if(root->val<l || root->val>r)
            return false;
        if(l>r) 
             return false;
        long curr = (long)root->val;
        return ( validate(root->left,l,curr-1) && validate(root->right,curr+1,r) );
        
        
    }*/
    
  /*  //Method -2.a (Inorder - Recursive)
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        return validate(root,prev);
    }
    
    bool validate(TreeNode* root, TreeNode* &prev)
    {
        if(!root) return true;
        if(!(validate(root->left,prev)))
            return false;
        if(prev!=NULL && prev->val>=root->val)
            return false;
        prev=root;
        return validate(root->right,prev);
        
    }*/
    
    //Method -2.b (Inorder - Iterative using stack)
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode* prev=NULL;
        stack<TreeNode*> s;
        
        while(root!=NULL || !s.empty())
        {
            while(root!=NULL)
            {
                s.push(root);
                root=root->left;
            }
            
            root=s.top();
            s.pop();
            
            if(prev!=NULL && prev->val >= root->val)
                return false;
            prev=root;
            
            root=root->right;
        }
        
        return true;
    }
};
