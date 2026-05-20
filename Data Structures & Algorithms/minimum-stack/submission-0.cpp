class MinStack {
public:
    multiset<int>ms;
     stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        ms.insert(val);
    }
    
    void pop() {
        auto it = find(ms.begin(),ms.end(),st.top());
        ms.erase(it);
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *ms.begin();
    }
};
