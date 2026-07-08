class MinStack {
    stack<int> st, minSt;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()) minSt.push(val);
        else{
            if(minSt.top() >= val) minSt.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()){
            if(minSt.top() == st.top()){
                minSt.pop();
            }

            st.pop();
        }
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
