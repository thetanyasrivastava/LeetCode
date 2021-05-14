/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/* MEthod -1 

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        set<Node*> vis;
        map<Node*, Node*> mp;
        dfs(node,vis,mp);
        addEdges(mp);
        return mp[node];
    }
    
    void dfs(Node* u, set<Node*> &vis, map<Node*, Node*> &mp)
    {
        //mark it visited
        vis.insert(u);
        
        //Create a copy and insert original and copy into map
        Node* ucopy= new Node(u->val);
        mp.insert({u,ucopy});
        
        //Create nodes of the neighbors of 'u' or to access the neighbors
        for(auto v: u->neighbors)
        {
            //check neighbors of original as copy do not have neighbors yet
            //unidiscovered node - node not found in set vis
            if(vis.find(v)==vis.end())
            {
             dfs(v,vis,mp);   
            }
        }
    }
    
    //function to link/join the nodes
    void addEdges(map<Node*, Node*> &mp)
    {
        //now to iterate in the map
        for(auto u:mp)
        {
            //iterate neighbors of u.first
            for(auto v: u.first->neighbors)
            {
                u.second->neighbors.push_back(mp[v]);
                //push neighbor of original to the copy's neighbors
            }
        }
    }
    
};*/



//Method - 2
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)   
            return NULL;
        
        if(mp.find(node)==mp.end())     //node not found in map (undiscovered node)
        {
            Node* copy=new Node(node->val);
            mp[node]=copy;
            
            for(auto x: node->neighbors)
            {
                copy->neighbors.push_back(cloneGraph(x));
            }
        }
        return mp[node];        //not return copy;
   }
private:
    unordered_map<Node*,Node*> mp;
};
