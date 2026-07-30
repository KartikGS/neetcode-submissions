class MinStack {
    stack<long> stk;
    int gmin;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(0);
            gmin = val;
            return;
        }
        stk.push(val-gmin);
        if(val-gmin<0) gmin = val;
    }
    
    void pop() {
        long top = stk.top();
        stk.pop();
        if(top<0) {
            gmin = gmin-top;
        }
    }
    
    int top() {
        if(stk.top()<0) return gmin;
        return (int)(stk.top()+gmin);
    }
    
    int getMin() {
        return gmin;
    }
};
