//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int s1=KnightPos[0]-1;
	    int s2=KnightPos[1]-1;
	    
	    int d1=TargetPos[0]-1;
	    int d2=TargetPos[1]-1;
	    
	    int count, steps=0;
	    
	    if(s1==d1 && s2==d2)
	        return 0;
	   
	   queue<pair<int,int>> q;
	   
	         
	   vector<vector<bool>> vis(N, vector<bool>(N,false)); 
	  /*vector<vector<bool>> vis; 
	   for(int i=0;i<N;i++)
	   {
	       for(int j=0;j<N;j++)
	        {
	            vis[i][j]=false;
	        }
	   }
	    //or vis[i].push_back(false); */
	    
	    
	    
	   q.push({s1,s2});
	   vis[s1][s2]=true;
	   count=q.size();
	   
	   bool flag=false;
	   while(count>0)
	   {
	       steps++;
	       for(int i=0;i<count;i++)
	       {
	           pair<int,int> p=q.front();
	           q.pop();
	           
	           expNeighbours(p.first,p.second,d1,d2,q,vis,flag,N);
	           
	           if(flag) 
	            return steps;
	       }
	       count=q.size();
	   }
	   return -1;
	}
	
	void expNeighbours(int x, int y, int d1, int d2, queue<pair<int,int>> &q,
	vector<vector<bool>> &vis, bool &flag, int N)
	{
	    int cx[]={-1,-1,1,1,-2,-2,2,2};
	    int cy[]={2,-2,2,-2,-1,1,-1,1};
	    
	    for(int i=0;i<8;i++)
	    {
	        int a=x+cx[i];
	        int b=y+cy[i];
	        
	        if(a>=0 && a<N && b>=0 && b<N && !vis[a][b]){
	        /*if(a<0 || a>=N || b<0 ||b>=N || vis[a][b])
                continue;*/
	            
	            if(a==d1 && b==d2)
	            {
	                flag=true;
	                return;
	            }
	            q.push({a,b});
	            vis[a][b]=true;
	        }
	    }
	}
	
};
