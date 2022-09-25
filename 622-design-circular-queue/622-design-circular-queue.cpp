class MyCircularQueue {
public:
    vector<int> q;
    int i, j;
    int sz;
    MyCircularQueue(int k) {
        q = vector<int>(k);
        i =0,j = 0;
        sz = k;
    }
    
    bool enQueue(int value) {
        if(j >= sz)
            return false;
        q[j++] = value;
        return true;
    }
    
    bool deQueue() {
        if(j == 0)
            return false;
        for(int k = 1;k<j;k++)
            q[k-1] = q[k];
        j--;
        return true;
    }
    
    int Front() {
        return j>0?q[0]:-1;
    }
    
    int Rear() {
        return j>0?q[j-1]:-1;
    }
    
    bool isEmpty() {
        return j == 0;
    }
    
    bool isFull() {
        return j >= sz;
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