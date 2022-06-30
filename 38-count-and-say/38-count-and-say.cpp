class Solution {
public:
    
    string solve(string str){
        string temp = "";
        if(str.size()==1){
            temp = temp + "1" + str[0];
            return temp;
        }
        int count = 1;
        int i;
        for(i=1;i<str.size();i++){
            if(str[i]==str[i-1]){
                count++;
            }else{
                temp += to_string(count);
                temp += str[i-1];
                count=1;
            }
        }
        
         temp += to_string(count);
        temp += str[i-1];
        return temp;
        
    }
    
    string countAndSay(int n) {
        
        if(n==1){
            return "1";
        }
        
        string ans = "1";
        
        for(int i=2;i<=n;i++){
            ans = solve(ans);
        }
        
        return ans;
        
    }
};