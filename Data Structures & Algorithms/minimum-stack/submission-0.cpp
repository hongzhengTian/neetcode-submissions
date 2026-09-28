class MinStack {
private:
    stack<int> values;
    stack<int> mins;

public:
    MinStack() {
        // 两个成员栈默认就是空的
    }

    void push(int val) {
        int currentMin = val;

        if (!mins.empty()) {
            currentMin = min(val, mins.top());
        }

        values.push(val);
        mins.push(currentMin);
    }

    void pop() {
        values.pop();
        mins.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return mins.top();
    }
};