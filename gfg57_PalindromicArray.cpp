/*Complete the function below*/
int PalinArray(int a[], int n)
{  //add code here.
    
    for(int i=0;i<n;i++)
    {
        int d,m=0;
        int j=a[i];
        
        while(j>0)
        {
            d=j%10;
            m=d+(m*10);
            j=j/10;
        }
        if(m!=a[i])
            return 0;
    }
    return 1;
}
