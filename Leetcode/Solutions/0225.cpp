class MyStack {
public:
  queue<int> q1;
    MyStack() {
        
    }
  void push(int x) {
        int size = q1.size();
        q1.push(x);
        for (int i = 0; i < size; ++i) {
            int elem = q1.front();
            q1.pop();
            q1.push(elem);
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        else{
        int elem=q1.front();
        q1.pop();
        return elem;
        }
    }
    
    int top() {
        if(q1.empty()) return -1;
        else return q1.front();
    }
    
    bool empty() {
         if(q1.empty()) return 1;
         else return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */