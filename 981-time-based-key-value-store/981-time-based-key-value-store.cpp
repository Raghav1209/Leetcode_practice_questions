class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        if(mp.find(key)!=mp.end()){
            
            mp[key][timestamp] = value;
            
        }else{
             mp[key][timestamp] = value;
        }
       
        
    }
    
    string get(string key, int timestamp) {
        
//         if(mp.find(key)!=mp.end()){
//             unordered_map<int,string> mp1 = mp[key];
            
//             if(mp1.find(timestamp)!=mp1.end()){
//                 return mp1[timestamp];
//             }else{
//                 int time = timestamp;
//                 while(time){
//                     if(mp1.find(time)!=mp1.end()){
//                         return mp1[time];
//                     }else{
//                         time--;
//                     }
//                 }
//             }
            
            // int time_prev = mp1.lower_bound(time);
            // return mp1[time_prev];
        
            if(mp.find(key) == mp.end())
        {
            return "";
        }
        string ans="";
        
        for(int currTime = timestamp; currTime >=1; currTime--)
        {
            if(mp[key].find(currTime) != mp[key].end())
                return mp[key][currTime];
        }
        
        return ans;
            
        // }
        // return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */