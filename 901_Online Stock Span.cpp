class StockSpanner {
public:
    int i;
      stack<int> s;
        vector<int> v;
      
       
    StockSpanner() {
       i=0;
    }
    
    int next(int price) {
        
       v.push_back(price);
         while(s.empty()==false && v[s.top()]<=v[i])
                s.pop();
            
            int span = (s.empty())?(i+1):(i-s.top());
            
            s.push(i++);
            return span;
        }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
