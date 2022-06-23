class Solution {
public:
    
    static bool mycmp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int n = courses.size();
        
        int sum = 0;
        
        sort(courses.begin(),courses.end(),mycmp);
        priority_queue<int> pq;
        
        for(auto i : courses){
            sum += i[0];
            pq.push(i[0]);
            
            if(sum>i[1]){
                sum -= pq.top();
                pq.pop();
            }
            
        }
        
        return pq.size();
        
    }
};