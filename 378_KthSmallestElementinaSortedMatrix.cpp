//Method - 1   Using MAX HEAP 
 // O(n*n log k)

class Solution {
public:
int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0)
            return 0;
        
        priority_queue<int> maxH;
        
        for(int i =0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                maxH.push(matrix[i][j]);
                
                if(maxH.size()>k)
                    maxH.pop();
            }
        }
        
        return maxH.top();
    }
};






//Method - 2 (Min Heap) [ O(n log k) ]

class Solution {
    typedef priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> ppi;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        if(n==0)
            return 0;
     ppi pq; 
     //or  -    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            pq.push({matrix[i][0],{i,0}});
        }
        
        while(pq.size()!=0)
        {
            auto t = pq.top();
            pq.pop();
            
            int val = t.first;
            int i = t.second.first;
            int j = t.second.second;
            
            if(++cnt==k)
                return val;
            
            if(j+1<n)
                pq.push({matrix[i][j+1],{i,j+1}});
        }
        return -1;
    }
};
