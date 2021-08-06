class Solution
{
    public:
    //Function to delete middle element of a stack.
    //Method - 1
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if(sizeOfStack==0)
            return;
        int mid;
        if(sizeOfStack % 2==0)
            mid=s.size()/2;
        else
            mid=(sizeOfStack/2)+1;
       
        solve(s,mid);
    }
        
    void solve(stack<int>&s, int mid)
    {
        if(s.size()==mid)
        {
            s.pop();
            return;
        }
        int top=s.top();
        s.pop();
        solve(s,mid);
        s.push(top);
    }
    
    //Method -2 
    /*void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if(sizeOfStack==0)
            return;
        int mid=(sizeOfStack/2)+1;
       
        solve(s,mid);
    }
        
    void solve(stack<int>&s, int mid)
    {
        if(mid==1)
        {
            s.pop();
            return;
        }
        int top=s.top();
        s.pop();
        solve(s,mid-1);
        s.push(top);
    }*/
};
