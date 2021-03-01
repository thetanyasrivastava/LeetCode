// T.C. = for push & pop : O(1)
// S.C. = O(n)


class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxFreq = max(maxFreq,++freq[x]);
        m[freq[x]].push(x);
    }
    
    int pop() {
        int x = m[maxFreq].top();
        m[maxFreq].pop();
        if(m[freq[x]--].size()==0)
            maxFreq--;
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */



