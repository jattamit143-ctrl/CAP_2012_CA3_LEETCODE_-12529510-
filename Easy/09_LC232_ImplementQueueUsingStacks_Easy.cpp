class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    // Move elements from inStack to outStack only when outStack is empty
    void transferIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int front = outStack.top();
        outStack.pop();
        return front;
    }
    
    int peek() {
        transferIfNeeded();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
