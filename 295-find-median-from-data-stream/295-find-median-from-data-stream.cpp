class MedianFinder {
public:
    
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxpq.size()==0){
            maxpq.push(num);
            return;
        }
        
        // if(minpq.size()==0){
        //     minpq.push(num);
        //     return;
        // }
        
        if(maxpq.size()==minpq.size()){
            if(num>minpq.top()){
                int y = minpq.top();
                minpq.pop();
                maxpq.push(y);
                 minpq.push(num);
            }else{
                
                // if(minpq.top()<maxpq.top()){
                //      int temp1 = minpq.top();
                //     int temp2 = maxpq.top();
                //     minpq.pop();
                //     maxpq.pop();
                //     minpq.push(temp2);
                //     maxpq.push(temp1);
                // }
               maxpq.push(num);
            }
        }else{
            if(num<maxpq.top()){
                int x = maxpq.top();
                maxpq.pop();
                minpq.push(x);
                maxpq.push(num);
            }else{
                minpq.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxpq.size()>minpq.size()){
            return maxpq.top();
        }else{
            return (maxpq.top()+minpq.top())/2.0;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */