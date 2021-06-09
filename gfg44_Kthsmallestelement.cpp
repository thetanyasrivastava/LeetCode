//Method - 1 HEap

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        /*//Min Heap
        
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=l;i<=r;i++)
        {
            minH.push(arr[i]);
        }
        int x;
        while(k--)
        {
            x=minH.top();
            minH.pop();
        }
        return x;*/
        
        //Max Heap
        priority_queue<int> maxH;

       
        for(int i=l;i<=r;i++)
        {
            maxH.push(arr[i]);

            if(maxH.size()>k)
                 maxH.pop();
            
        }
        return maxH.top();
    }
};
