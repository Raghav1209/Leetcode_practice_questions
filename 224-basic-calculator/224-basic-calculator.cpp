class Solution {
public:
    int calculate(string s) {
        
        int sign = 1;
        int i = 0;
        int len = s.size();
        stack<int> st;
        int result = 0;
        
        while(i<len){
            
            if(s[i]==' '){
                i++;
                continue;
            }
            else if(s[i]=='+'){
                sign = 1;
            }else if(s[i]=='-'){
                sign = -1;
            }else if(isdigit(s[i])){
                
                
                long num = 0;
                
                while(i<len && isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }
                
                result += num*sign;
                i--;
                            
                
            }else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }else{
                int xsign = st.top();
                st.pop();
                int xresult = st.top();
                st.pop();
                
                result = result*xsign + xresult;
                
            }
            i++;
        }
        
        return result;
        
    }
};