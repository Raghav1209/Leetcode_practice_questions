class Solution {
public:
    string fractionToDecimal(int num, int den) {
        
        string ans = "";
        
        if(num==0){
            return "0";
        }
        
        if((num>0)^(den>0)){
            ans += "-";
        }else{
            ans = "";
        }
        
        long n = abs(num);
        long d = abs(den);
        
        ans += to_string(n/d);
        
        n = n%d;
        
        if(!n){
            return ans;
        }
        
        ans += ".";
        
        unordered_map<long,int> mp;
        
        while(n){
            
            if(mp[n]){
                ans.insert(mp[n],"(");
                ans += ")";
                break;
            }else{
                mp[n] = ans.size();
                n *= 10;
                ans += to_string(n/d);
                n = n%d;
            }
            
        }
        
        return ans;
        
    }
};