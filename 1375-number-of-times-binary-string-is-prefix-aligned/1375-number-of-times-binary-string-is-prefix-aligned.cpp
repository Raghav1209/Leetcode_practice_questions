class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        
        int count = 0;
        int maxx = 0;
        
        for(int i=0;i<flips.size();i++){
            maxx = max(maxx,flips[i]);
            if(maxx == i+1){
                count++;
            }
        }
        
        return count;
        
    }
};