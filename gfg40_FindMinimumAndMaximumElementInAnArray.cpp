pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> p;
    
    long long maxm, minm;
    long long i;
    if(n%2==0)
    {
        if(a[0]>a[1])
        {
            maxm=a[0];
            minm=a[1];
        }
        else
        {
            maxm=a[1];
            minm=a[0];
        }
        i=2;
    }
    else{
        maxm=a[0];
        minm=a[0];
        i=1;
    }
    
    while(i < n-1)
    {
        if(a[i]>a[i+1])
        {
            if(a[i] > maxm)
            {
                maxm=a[i];  
            }
            if(a[i+1] < minm)
            {
                minm=a[i+1];
            }
           // maxm=max(a[i],maxm);
            //minm=min(a[i+1],minm);
        }
        
        else
        {
            if(a[i+1]>maxm)
            {
                maxm=a[i+1];
            }
            
            if(a[i]<minm)
            {
                minm=a[i];
            }
            //maxm=max(a[i+1],maxm);
            //minm=min(a[i],minm);
        }
        i+=2;
        
    }/*
    //vector = sort(a.begin(), a.end());
    sort(a,a+n);
    minm=a[0];
    maxm=a[n-1];*/
    p.first=minm;
    p.second=maxm;
    
    return p;
}
