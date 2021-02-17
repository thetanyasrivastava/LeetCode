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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        if(!root) return result;
        
        unordered_map<TreeNode*, TreeNode*> parentTrack;    //node->parent
        unordered_map<TreeNode*, bool> visited;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())           //First BFS to get a track of parent node
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                parentTrack[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parentTrack[curr->right]=curr;
                q.push(curr->right);
            }
        }
        
        q.push(target);
        visited[target]=true;
        int currLevel=0;
        
        while(!q.empty())       //Second BFS to go upto K level from target node &                                      //using our Hash table
        {
            int size=q.size();
            if(currLevel++ == K)
                break;
            
            while(size--)
            {
            TreeNode* curr=q.front();
            q.pop();
            
                    
            if(curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parentTrack[curr] && !visited[parentTrack[curr]])
            {
                q.push(parentTrack[curr]);
                visited[parentTrack[curr]]=true;
            }
            }
        }
        
        
        while(!q.empty())
        {
            TreeNode* curr=q.front(); q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};
