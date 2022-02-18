class Solution {
public:
    string removeKdigits(string num, int k) {
        
       stack<char> s;
        int n = num.length();
        int j;
        
        if(k==n){
            return "0";
        }
        
       for( char c : num){
           while(!s.empty() && k>0 && s.top()>c){
               s.pop();
               k--;
           }
           
           if(s.empty() && c=='0'){
               continue;
           }else{
               s.push(c);
           }
       }
        
        while(!s.empty() && k!=0){
            s.pop();
            k--;
        }
        
        if(s.empty()){
            return "0";
        }
        
        string str = "";
        
        while(!s.empty()){
            str += s.top();
            s.pop();
        }
        
        reverse(str.begin(),str.end());
        
        return str;
        
        
        
    }
};