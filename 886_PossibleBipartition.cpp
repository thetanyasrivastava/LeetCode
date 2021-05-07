// GFG - https://practice.geeksforgeeks.org/problems/bipartite-graph/1#
// LC - 886. Possible Bipartition & 785. Is Graph Bipartite?

class Solution {
public:
    /*DFS
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        
        vector<int> col(N+1,-1);
        vector<vector<int>> graph(N+1);
        
        for(auto x:dislikes)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        bool flag=true;
        for(int i=1;i<N+1;i++)
        {
            if(col[i]==-1)
            {
                flag=bipartite(graph,col,i,N,0);
                if(!flag)
                    return false;
            }
        }
        return true;
    }
    
    bool bipartite(vector<vector<int>> &graph,vector<int>& col,int start,int N,
                   int cr)
    {
        col[start]=cr;
        bool flag=true;
        
        for(auto v:graph[start])
        {
            if(col[v]==-1)
            {
                flag=bipartite(graph,col,v,N,1-cr);
                if(!flag)
                    return false;
            }
            else if(col[v]==col[start])
                return false;
        }
        return true;
    }*/
        
         //BFS
     bool possibleBipartition(int N, vector<vector<int>>& dislikes) {  
       
        vector<vector<int>> graph(N+1);  
          //for converting array of pairs(dislikes) into adjacency list
    for(auto i:dislikes)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
          
        vector<int> color(N+1,-1);
        for(int i=1;i<=N;i++)
        {
            if(color[i]==-1)
            {
                if(!isBipartite(graph,color,N,i))
                    return false;
            }
        }
        return true;
      }
    
    bool isBipartite(vector<vector<int>> &graph,vector<int> &color,int N, int start)
    {
        queue<int> q;
        q.push(start);
        color[start]=1;
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            
            for(int node:graph[curr])
            {   
                if(color[node]==color[curr])        //Odd Length Cycle
                    return false;       
                if(color[node]==-1)               //Unvisited
                {
                    color[node]=1-color[curr];
                    q.push(node);
                }
            }
        }
        return true;
    }
       
};

    
