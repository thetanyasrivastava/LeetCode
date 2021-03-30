class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        
        stack<int> s;
        s.push(arr[0]);
        //int p=INT_MIN;
        int p=0;
        
        for(int i=1;i<N;i++)
        {
            while(!s.empty() && s.top()<arr[i])
            {
               p=s.top();
               s.pop();
            }
            
            if(arr[i]<p)
                return 0;
            
            s.push(arr[i]);
        }
        return 1;
    }
    
};
