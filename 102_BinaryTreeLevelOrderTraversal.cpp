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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==NULL)
            return answer;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty())
        {   
            int size =Q.size();    //storing queue size for while loop
            vector<int> v;      //for storing nodes at the same level
            while(size>0)
            {
                
                TreeNode* current = Q.front();
                
                v.push_back(current->val);
                if(current->left!=NULL)
                {   
                    Q.push(current->left);
                }
                if(current->right!=NULL)
                {
                    Q.push(current->right);
                }
                Q.pop();
                size--;
             }
            answer.push_back(v);        //push v into answer, as v consists of all                                          //nodes of current level
     
        }
    return answer;
        
    }
};
