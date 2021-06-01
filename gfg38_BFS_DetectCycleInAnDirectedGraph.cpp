//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution
{ 
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    //BFS
	    queue<int> q;
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto x : adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    int count=0;
	    while(!q.empty())
	    {
	        int curr=q.front();
	        q.pop();
	        
	        count++;
	        
	        for(auto x: adj[curr])
	        {
	            indegree[x]--;
	            if(indegree[x]==0)
	                q.push(x);
	        }
	    }
	    
	    if(count==V)        //No Cycle
	        return false;
	    
	    return true;
	}
};
