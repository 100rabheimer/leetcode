class MyQueue {
public:
stack<int>s1;
stack<int>s2;

    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x); //pehle s1 mein dALEWNEG  then s2 mein push kr denge taki queue ka fifo maintain rhe 
    }
    
    int pop() {
        if(s2.empty()){//agar s2 khali rha tbhi toh usme hm s1 se nikal ke bhrenge 
        while(!s1.empty()){//jbtk s1 khali nhi hota
            s2.push(s1.top());
            s1.pop();
        }}
        int front=s2.top();
        s2.pop();
        return front;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();//queue tbhi khali hoga if s1 and s2 dono khali hain
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */