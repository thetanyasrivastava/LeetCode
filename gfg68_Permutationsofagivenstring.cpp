class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> res;
		    int len=S.length();
		    permu(0,len,S,res);
		    sort(res.begin(),res.end());
		    return res;
		}
		
		void permu(int pos,int len,string &s,vector<string> &res)
		{
		    if(pos==len-1)
		    {
		        res.push_back(s);
		        return;
		    }
		    
		    for(int i=pos;i<=len-1;i++)
		    {
		        swap(s[pos],s[i]);
		        permu(pos+1,len,s,res);
		        swap(s[pos],s[i]);
		    }
		    
		}
};
