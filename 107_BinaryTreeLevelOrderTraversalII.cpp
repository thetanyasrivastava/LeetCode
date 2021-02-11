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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        stack<vector<int>> s;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            
            while(size--)
            {
                TreeNode *temp=q.front();
                level.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
                q.pop();
            }
            s.push(level);
        }
        
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
        
    }
};
