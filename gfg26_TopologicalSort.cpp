class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int> v;
	    bool vis[V];
	    for(int i=0;i<V;i++)
	        vis[i]=false;
	        
	   stack<int> s;
	   
	   for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	        {
	   	            dfs(V,adj,i,vis,s);
	   	       }
	   	}
	   while(!s.empty())
	    {
	        v.push_back(s.top());
	        s.pop();
	    }
	    
	    return v;
	}
	
	void dfs(int V,vector<int> adj[], int start, bool vis[], stack<int> &s)
	{
	    vis[start]=true;
	    for(auto node : adj[start])
	    {
	        if(!vis[node])
	            dfs(V,adj,node,vis,s);
	    }
	    s.push(start);
	}
};
