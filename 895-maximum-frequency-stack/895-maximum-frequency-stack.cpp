class FreqStack {
public:
    
    map<int,int> setFreq;
    map<int,stack<int>> setMap;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = setFreq[val]+1;
        
        setFreq[val]++;
        if(freq>maxFreq){
            maxFreq = freq;
        }
        
        setMap[freq].push(val);
        
    }
    
    int pop() {
        
        int top = setMap[maxFreq].top();
        
        setMap[maxFreq].pop();
        
        setFreq[top]--;
        
        if(setMap[maxFreq].size()==0){
            maxFreq--;
        }
        
        return top;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */