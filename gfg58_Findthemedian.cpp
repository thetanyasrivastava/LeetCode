Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    sort(v.begin(),v.end());
		    int n=v.size();
		   
		    if(n%2==0)
		    {
		        int m=n/2;
		        return (v[m] + v[m-1])/2;
		    }
		   return v[n/2];
		}
};
