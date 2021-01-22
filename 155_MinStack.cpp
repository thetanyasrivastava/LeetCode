class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> s;
    
   long minEle;
    
    MinStack() {
        
    }
    
    void push(int x) {
        long xx = (long) x;
        if(s.size()==0)
        {
            s.push(xx);
            minEle=xx;
        }
        else 
        {
            if(xx>=minEle)
                s.push(xx);
            else if(xx<minEle)
            {
                
                s.push(2*xx-(minEle));
                minEle=xx;
            }
        }
    }
    
    void pop() {
      
        if(s.size()==0)
            return;
        else
        {
              long tp = s.top();
            if(tp>=minEle)
                s.pop();
            else if(tp<minEle)
            {
                minEle = (2*minEle) - tp;
                s.pop();
            }
        }
    }
    
    int top() {
        
        if(s.size()==0)
            return 0;
        else
        {
            long tp = s.top();
            if(tp>=minEle)
                return (int)tp;
            else
                return (int)minEle;
        }
            
    }
    
    int getMin() {
        if(s.size()==0)
            return -1;
        
        return (int)minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
