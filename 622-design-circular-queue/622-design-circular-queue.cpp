class MyCircularQueue {
public:
    vector<int> q;
    int sz;
    MyCircularQueue(int k) {
        sz = k;
    }
    
    bool enQueue(int value) {
        if(q.size() >= sz)
            return false;
        q.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(q.size() == 0)
            return false;
        reverse(q.begin(),q.end());
        q.pop_back();
        reverse(q.begin(),q.end());
        return true;
    }
    
    int Front() {
        return q.size()>0?q[0]:-1;
    }
    
    int Rear() {
        return q.size()>0?q[q.size()-1]:-1;
    }
    
    bool isEmpty() {
        return q.size() == 0;
    }
    
    bool isFull() {
        return q.size() >= sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */