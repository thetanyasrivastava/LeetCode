//

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        
       /* //Method 1 , T.C. O(n^2) S.C. = O(1)
        int count=0,minlen=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=0;//,count=0;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
               // count++;
                if(sum>x){
                    minlen=min(minlen,j-i+1);
                }
            }
        }
        return minlen;*/
        
        //Method 2 - Sliding Window, 
        //T.C. O(n) S.C. = O(1)
        int count=0,ws=0,minlen=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            count++;
            
            while(sum>x)
            {
                minlen=min(minlen,count);
                sum-=arr[ws];
                ws++;
                count--;
            }
        }
        return minlen;
    }
};
