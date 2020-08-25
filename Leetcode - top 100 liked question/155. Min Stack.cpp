class MinStack {
public:
    stack<pair<int,int>> s;
    long long int min=INT_MAX;
    MinStack() {
    }
    
    void push(int x) {
        if(x<this->min)
        {
            this->s.push(pair<int,int>(x,x));
            this->min=x;
        }
        else
        {
            if(this->s.empty())this->s.push(pair<int,int>(x,x));
            else this->s.push(pair<int,int>(x,this->s.top().second));
        }
                
    }
    
    void pop() {
        if(s.empty())return;
        this->s.pop();
        if(s.empty())
        {
            this->min=INT_MAX;
            return;
        }
        this->min=this->s.top().second;
    }
    
    int top() {
     return this->s.top().first;   
    }
    
    int getMin() {
           return this->min;   
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
