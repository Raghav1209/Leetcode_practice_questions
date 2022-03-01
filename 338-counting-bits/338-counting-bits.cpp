class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> v;
        v.push_back(0);
        
        if(n==0){
            return v;
        }
        
        for(int i=1;i<=n;i++){
            int count = 0;
             string binary = bitset<32>(i).to_string();
            for(int i=0;i<binary.length();i++){
                if(binary[i]=='1'){
                    count += 1;
                }
                
            }
             v.push_back(count);
        }
        
        
        return v;
           
        
    }
};