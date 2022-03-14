class Solution {
public:
    string simplifyPath(string str) {
        
        stack<string> st;
        int i;
        string res = "";
        for(i=0;i<str.length();i++){
            if(str[i]=='/'){
                continue;
            }
            
            string temp = "";
            
            while(i<str.length() && str[i]!='/'){
                temp += str[i];
                i++;
            }
            
            if(temp=="."){
                continue;
            }else if(temp==".."){
                if(!st.empty())
                    st.pop();
            }else{
                st.push(temp);
            }
            
        }
        
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size()==0){
            return "/";
        }
        
         // reverse(res.begin(),res.end());
        
        return res;
        
    }
};