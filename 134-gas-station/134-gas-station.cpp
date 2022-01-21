class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      
        int n = gas.size();
        // for(int i=0;i<n;i++){
        //    int fuel = 0;
        //     int j = i;
        //     int stopcount=0;
        //     while(stopcount<n){
        //         int x =gas[j%n]-cost[j%n];
        //         fuel += x;
        //         if(fuel<0){
        //             break;
        //         }
        //         stopcount++;
        //         j++;
        //     }
        //     if(stopcount==n && fuel>=0){
        //         return i;
        //     }
        // }
        // return -1;
        int start=0;
        int totalfuel = 0;
        int fuel = 0;
        for(int i=0;i<n;i++){
            totalfuel += gas[i]-cost[i];
            fuel += gas[i]-cost[i];
            if(fuel<0){
                fuel = 0;
                start = i+1;
            }
        }
        return(totalfuel>=0)?start:-1;
        
                        
            
    }  
        
};