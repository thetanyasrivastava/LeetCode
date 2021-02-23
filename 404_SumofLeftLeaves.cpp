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
    int sumOfLeftLeaves(TreeNode* root) {
       /*DFS
       if(!root) return 0;
    
       if(root->left && !root->left->left && !root->left->right)
           return root->left->val + sumOfLeftLeaves(root->right);
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        */
       // BFS
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int sum=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) {
                    if(!curr->left->left && !curr->left->right)
                        sum+=curr->left->val;
                    else
                        q.push(curr->left);
                }
                
                if(curr->right) 
                    q.push(curr->right);

            }
            
        }
        return sum;
        
        
    }
};
