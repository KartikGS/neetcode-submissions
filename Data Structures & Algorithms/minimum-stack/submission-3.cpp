class MinStack {
    stack<int> stk;
    stack<int> mstk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        mstk.push(min(val, mstk.empty()?val:mstk.top()));
    }
    
    void pop() {
        stk.pop();
        mstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
};
