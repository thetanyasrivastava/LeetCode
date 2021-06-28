//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        // if(n<3)
        //     return false;
        sort(A,A+n);
        for(int i=0;i<n-2;i++)
        {
            // if(i==0 || (i>0 && A[i]!=A[i-1]))
            // {
                int lo=i+1, hi=n-1;
                int sum=X-A[i];
                
                while(lo<hi)
                {
                    if(A[lo]+A[hi]==sum)
                    {
                         return true;
                    }
                    else if(A[lo]+A[hi]<sum)
                        {
                            //to avoid duplicates if mentioned in ques ->
                            // while(lo<hi && A[lo]==A[lo+1])
                            //     lo++;
                            lo++;
                        }
                    else {
                        //  while(lo<hi && A[hi]==A[hi-1])
                        //       hi--;
                           hi--;
                    }
                        
                }
            // }
        }
        return false;
    }

};
