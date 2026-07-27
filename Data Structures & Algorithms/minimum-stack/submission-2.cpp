class MinStack {
    stack<int> s1;
    stack<int> s2;
public:
    MinStack() { 
        s1 = {};
        s2 = {};    
    }
    
    void push(int val) {
        if(s2.empty()){
            s2.push(val);
        }
        else {
            s2.push(min(val,s2.top()));
        }
        s1.push(val);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
