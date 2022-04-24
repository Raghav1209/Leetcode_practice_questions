class UndergroundSystem {
public:
    
    map<int,pair<string,int>> inTransit;
    map<string,pair<long long,int>> stationTimes;

    UndergroundSystem() {
        inTransit.clear();
        stationTimes.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        
        if(inTransit.find(id)!=inTransit.end()){
            return;
        }else{
            inTransit[id] = {stationName,t};
        }
        
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto& info = inTransit[id];
        string startStation = info.first;
        int time = info.second;
        string key = startStation  + ":" + stationName;
        int diff = t-time;
        
        
        if(stationTimes.find(key)!=stationTimes.end()){
            auto& oldTimes = stationTimes[key];
            oldTimes.first += diff;
            oldTimes.second++;
        }else{
            stationTimes[key] = {diff,1};
        }
        
        inTransit.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        string key = startStation + ":" + endStation;
        double avg = (double)stationTimes[key].first/(double)stationTimes[key].second;
        return avg;

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */