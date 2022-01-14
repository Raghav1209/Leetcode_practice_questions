class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int flag=0;
        int flag2 = 0;
        int flag3 = 0;
        int flag4 = 0;
        long long int num = 0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='+' || s[i]=='-'){
                if(flag2 || flag3 || flag4){
                    break;
                }
                if(s[i]=='-'){
                    flag=1;
                }
                flag2 = 1;
            }
            else if(s[i]==' '){
                if(flag4 || flag2){
                    break;
                }
                continue;
            }
            else if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || s[i]=='.'){
                 break;
            }else{
                flag4 = 1;
                int x = s[i] - '0';
                if(x==0){
                    flag3 = 1;
                }
                num = (num*10) + x;
                // if(num < INT_MIN){
                //     return INT_MIN;
                // }
                if(num>INT_MAX){
                    if(flag){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
                // num = num*10;
                
            }
            
        }
         // num = num/10;
            if(flag){
                return (num*-1);
            }else{
                return num;
            }
    }
};