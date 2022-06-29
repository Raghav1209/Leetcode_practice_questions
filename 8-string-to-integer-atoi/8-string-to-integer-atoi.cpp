class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size();
        int i = 0;
        bool neg = false;
        
        while(i<n){
            if(s[i]==' '){
                i++;
            }else{
                break;
            }
        }
        
        
        if(s[i]=='-'){
            neg = true;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        
        while(i<n){
            if(s[i]!='0'){
                break;
            }else{
                i++;
            }
        }
        
        string str = "";
        long long res = 0;
        int p = 0;
        bool ovf = false;
        
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                str += s[i];
            }else{
                break;
            }
            i++;
        }
        // cout<<str<<" ";
        int j = str.size()-1;
        while(j>=0){
            
            int val = str[j]-'0';
            res += val*pow(10,p);
            
            if((p>10) || res>INT_MAX){
                ovf = true;
                break;
            }
            j--;
            p++;
            
        }
        
        if(ovf){
            if(neg){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }
        
        if(neg){
            return res*-1;
        }else{
            return res;
        }
        
        
        
        
        
    }
};