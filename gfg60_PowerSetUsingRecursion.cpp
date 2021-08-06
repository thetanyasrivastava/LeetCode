void solve(string s, string &op,vector<string> &res)
{
    if(s.length()==0){
        //cout<<op<<endl;
        res.push_back(op);
        return;
    }
    
   string op1=op;
   string op2=op;
        
    op2 += s[0];
    s.erase(s.begin()+0);
    
    solve(s,op1,res);
    solve(s,op2,res);
    
}       
//Function to return the lexicographically sorted power-set of the string.
vector <string> powerSet(string s)
{
   //Your code here
   vector<string> res;
   string op="";
   //res.push_back(op);
   solve(s,op,res);
   //res.push_back(op);
   return res;
}
