class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> v;
	    queue<int> q;
	    vector<bool> vis(V,false);
	    
	    q.push(0);
	    vis[0]=true;
	    
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        v.push_back(temp);
	    
	        for(int v=0;v<adj[temp].size();v++)
	        {
	            if(!vis[adj[temp][v]])
	           {
	               q.push(adj[temp][v]);
	               vis[adj[temp][v]]=true;
	           }
	        }
	    }
	    return v;
	}
};
