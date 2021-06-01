//https://practice.geeksforgeeks.org/problems/topological-sort/1

//T.C. = O(N+E)
//S.C. = O(N) + O(N) = O(N)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	//BFS - Kahn's Algorithm
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int curr=q.front();
	        q.pop();
	        
	        topo.push_back(curr);
	        
	        for(auto x: adj[curr])
	        {
	            indegree[x]--;
	            if(indegree[x]==0)
	                q.push(x);
	        }
	    }
	    
	    return topo;
	}
  
  };
