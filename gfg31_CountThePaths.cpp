class Solution {
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<bool> vis(n,false);
	    int count=0;
	    vector<vector<int>> graph(n);
	    
	    for(auto i: edges)
	        graph[i[0]].push_back(i[1]);
	        
	   dfs(s,d,vis,graph,count);
	    
	    return count;
	}
	
	void dfs(int start,int d,vector<bool> &vis ,vector<vector<int>> graph,int &count)
	{
	    if(start==d)
	    {
	       count++;
	       return;
	     }
	     
	     vis[start]=true;
	     
	     for(auto node: graph[start])
	     {
	         if(!vis[node])
	            dfs(node,d,vis,graph,count);
	     }
	     
	     vis[start]=false;
	}
};
