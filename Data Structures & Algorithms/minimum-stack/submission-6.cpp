class MinStack {
    stack<long> stk;
    long min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(0);
            min = val;
            return;
        }
        stk.push(val-min);
        if(val-min<0) min = val;
        return;
    }
    
    void pop() {
        if(stk.empty()) return;

        long top = stk.top();
        stk.pop();

        if(top<0) min-=top;
    }
    
    int top() {
        long top = stk.top();
        return top<0? (int)min:top+min;
    }
    
    int getMin() {
        return (int)min;
    }
};
