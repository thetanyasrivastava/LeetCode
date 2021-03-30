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
   //Method -1 Recursive
    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        
        inorder(root,v);        
        return v;
    }
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }*/
    
    //Method -2 Iterative using stack
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> v;
        if(!root) return v;
        
        stack<TreeNode*> s;
        
        while(root!=NULL || !s.empty())
        {
            while(root!=NULL)
            {
                s.push(root);
                root=root->left;        //iterate until we reach the leftmost node
            }
            
            root=s.top();
            s.pop();
            
            v.push_back(root->val);     //process the node
            
            root=root->right;           //right node
        }
        
        return v;
    }
};
