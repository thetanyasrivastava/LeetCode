class Solution{
public:	
    
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    string op="";
	    int one=0;
	    int zero=0;
	    vector<string> res;
    
	    solve(one,zero,N,op,res);
	    return res;
	}
	
	void solve(int one,int zero,int N,string op,vector<string> &res)
	{
	    if(N==0)
	    {
	        res.push_back(op);
	        return;
	    }
	    
	    string op1=op;
	    op1.push_back('1');
	    solve(one+1,zero,N-1,op1,res);
	    
	    if(one>zero)
	    {
	        string op2=op;
	        op2.push_back('0');
	        solve(one,zero+1,N-1,op2,res);
	    }
	}
};
