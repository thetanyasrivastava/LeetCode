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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> q;
        q.push(s);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->val == t->val)
            {
                bool isI = identical(temp,t);
                if(isI)
                    return true;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return false;
    }
    
    bool identical(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;
        
        return identical(root1->left,root2->left) && identical(root1->right,root2->right);
    }
};
