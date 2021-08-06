class Solution{
    public:
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
   
        if(arr.size()==1)
        {
            return arr;
        }
         
        int temp=arr[n-1];
        arr.pop_back();
        sortArr(arr,n);
        insert(arr,temp,n);
        return arr;
    }
    
    void insert(vector<int> &arr, int temp,int n)
    {
        
        if(n==0 || arr[n-1]<=temp)
        {
            arr.push_back(temp);
            return;
        }
        
        int val=arr[n-1];
        arr.pop_back();
        insert(arr,temp,n);
        arr.push_back(val);
        return;
     
    }
};
