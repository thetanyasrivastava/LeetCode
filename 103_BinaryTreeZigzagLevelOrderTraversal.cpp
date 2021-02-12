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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        
        stack<TreeNode*> s1,s2;
        
        s1.push(root);
        
        while(!s1.empty() || !s2.empty())
        {   
            vector<int> v1;
            while(!s1.empty())
            {
               TreeNode* temp=s1.top();
               v1.push_back(temp->val);
                s1.pop();
                if(temp->left!=NULL) s2.push(temp->left);
                if(temp->right!=NULL) s2.push(temp->right);
            }
            res.push_back(v1);
            
            
             vector<int> v2;
            while(!s2.empty())
            {
               TreeNode* temp=s2.top();
               v2.push_back(temp->val);
                s2.pop();
               
                if(temp->right!=NULL) s1.push(temp->right);
                 if(temp->left!=NULL) s1.push(temp->left);
                
            }
            if(v2.size()>0)
                res.push_back(v2);
            
        }
        return res;
    }
};
