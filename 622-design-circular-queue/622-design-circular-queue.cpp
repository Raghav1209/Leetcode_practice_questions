class MyCircularQueue {
public:
    vector<int> v;
    int rear;
    int front;
    int N;
    MyCircularQueue(int k) {
        v.resize(k);
        rear = -1;
        front = -1;
        N = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        
        if(isEmpty()){
            front = 0;
        }
        
        rear = (rear+1)%N;
        v[rear] = value;
        return true;
        
    }
    
    bool deQueue() {
        
        if(isEmpty()){
            return false;
        }
        
        if(front==rear){
            rear = -1;
            front = -1;
        }
        else{
            front = (front+1)%N;
        }
        return true;
        
        
    }
    
    int Front() {
        if(!isEmpty()){
            return v[front];
        }else{
            return -1;
        }
    }
    
    int Rear() {
        if(!isEmpty()){
            return v[rear];
        }else{
            return -1;
        }
    }
    
    bool isEmpty() {
        
        return front == -1;
        
    }
    
    bool isFull() {
        
        return ((rear+1)%N) == front;
        
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