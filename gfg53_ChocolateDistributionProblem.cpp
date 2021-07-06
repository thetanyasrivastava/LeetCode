//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long i=0;
    long long minm=LLONG_MAX;
    long long maxm=LLONG_MIN;
    long long ans=LLONG_MAX;
    
    //while((i+m-1)<n)
    while(i<=n-m)
    {
        minm=a[i];
        maxm=a[i+m-1];
        ans=min(ans,maxm-minm);
        i++;
    }
    return ans;
    }   
};
