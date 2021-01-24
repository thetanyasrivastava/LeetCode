class Solution {
public:
    int calPoints(vector<string>& ops) {
        if (ops.empty())
            return 0;
        stack<string> s;
        //s.push(ops[0]);
        for (auto c : ops)
        {
            if(c=="+")
            {
                string a = s.top();  s.pop();
                string b = s.top();  s.pop();
                
                int d =stoi(a) + stoi(b);
                s.push(b); s.push(a); s.push(to_string(d));
                
            }
            else if(c=="D")
            {
                string a = s.top(); s.pop();
                int d = stoi(a) * 2;
                s.push(a);
                s.push(to_string(d));
                
                
		    }
            
            else if(c=="C")
                s.pop();
           
            else
                s.push(c);
            
           
        }
        int sum=0;
        while(!s.empty())
        {
            sum += stoi(s.top());
        
            s.pop();
            
        }
        
        return sum;
        
    }
};
