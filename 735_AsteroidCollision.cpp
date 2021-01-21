class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> v;
        if(asteroids.size()==0)
            return v;
        
        stack<int> s;
        
        for(int i=0;i<asteroids.size();i++)
        {
            class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> v;
        if(asteroids.size()==0)
            return v;
        
        stack<int> s;
        
        for(int i=0;i<asteroids.size();i++)
        {
           
            //Only handle when new element is negative, else if positive , simply push to stack
            if(asteroids[i]<0)
            {
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i]))
                    s.pop();
                
                if(s.empty() || s.top()<0)
                    s.push(asteroids[i]);
                else if(s.top()==abs(asteroids[i]))
                    s.pop();         
            }
            else
                s.push(asteroids[i]);
        }
        
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();            
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
            //Only handle when new element is negative, else if positive , simply push to stack
            if(asteroids[i]<0)
            {
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i]))
                    s.pop();
                
                if(s.empty() || s.top()<0)
                    s.push(asteroids[i]);
                else if(s.top()==abs(asteroids[i]))
                    s.pop();         
            }
            else
                s.push(asteroids[i]);
        }
        
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();            
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
