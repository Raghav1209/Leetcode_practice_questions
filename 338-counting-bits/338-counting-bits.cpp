class Solution {
public:
    
    int solve(int n,vector<int>& memo){
        
        if(n==0){
            return 0;
        }
        
        if(n==1){
            return 1;
        }
        
        if(memo[n]==0){
        
        if(n%2==0){
            memo[n] = solve(n/2,memo);
            return solve(n/2,memo);
        }else{
            memo[n] = 1+solve(n/2,memo);
            return 1+solve(n/2,memo);
        }
            
        }else{
            return memo[n];
        }
        
    }
    
    vector<int> countBits(int n) {
        
        vector<int> memo(n+1,0);
        // int memo[n+1];
//         v.push_back(0);
        
//         if(n==0){
//             return v;
//         }
        
//         for(int i=1;i<=n;i++){
//             int count = 0;
//              string binary = bitset<32>(i).to_string();
//             for(int i=0;i<binary.length();i++){
//                 if(binary[i]=='1'){
//                     count += 1;
//                 }
                
//             }
//              v.push_back(count);
//         }
        
        
//         return v;
        
        for(int i=0;i<=n;i++){
            // int x = solve(i,memo);
            memo[i]=solve(i,memo);
        }
          return memo; 
        
    }
};