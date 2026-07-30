class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minStk.empty()){
            minStk.push(val);
            return;
        }
        minStk.push(minStk.top()<val?minStk.top():val);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
