class Solution
{
    public:
    /*
    Method-1
    void sort012(int a[], int n)
    {
        // coode here 
        int c0=0,c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                c0++;
            else if(a[i]==1)
                c1++;
            else
                c2++;
        }
        for(int i=0;i<c0;i++)
         {   a[i]=0;}
        for(int i=c0;i<n-c2;i++)
            {a[i]=1;}
        for(int i=c1+c0;i<n;i++)
           { a[i]=2;}
    }*/
    
    //Method-2
    void sort012(int a[], int n)
    {
        int lo=0,mid=0,hi=n-1;
        while(mid<=hi)
        {
            if(a[mid]==0)
            {
                swap(a[lo++],a[mid++]);
            }
            else if(a[mid]==1)
                mid++;
            else
                swap(a[mid],a[hi--]);
        }
    }
};
