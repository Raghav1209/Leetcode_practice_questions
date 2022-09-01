class Solution {
public:
    int garbageCollection(vector<string>& gar, vector<int>& travel) {
        
        int last_g;
        int last_p;
        int last_m;
        int count = 0;
        for(int i=0;i<gar.size();i++){
            for(auto it : gar[i]){
                if(it=='M'){
                    last_m = i;
                }else if(it=='G'){
                    last_g = i;
                }else{
                    last_p = i;
                }
                count++;
            }
        }
        int total = count;
        int sum = 0;
        for(int i=0;i<travel.size();i++){
            sum += travel[i];
            if(last_g==i+1){
                total += sum;
            }
            if(last_p==i+1){
                total += sum;
            }
            if(last_m==i+1){
                total += sum;
            }
        }
        
        return total;
        
    }
};