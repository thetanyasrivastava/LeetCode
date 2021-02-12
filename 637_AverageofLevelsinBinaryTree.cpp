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
    vector<double> averageOfLevels(TreeNode* root) {
         vector<double> res;
        if(!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        
        while(!q.empty())
        {
            double avg = 0;
            int size = q.size();
            int n=size;
            vector<int> level;
            
            while(size--)
            {
                TreeNode *temp=q.front();
                level.push_back(temp->val);
                avg += temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
                q.pop();
                
            }
           avg =(double)avg/n;
            res.push_back(avg);
        }
    
        return res;
    }
};
