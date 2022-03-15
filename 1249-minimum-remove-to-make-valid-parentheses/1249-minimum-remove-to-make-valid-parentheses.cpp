class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
         stack<char> st;
         unordered_set<int> ss;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    ss.insert(i);
                }
            }else{
                continue;
            }
        }
        
        string str = "";
        
        
        if(!st.empty()){
            for(int i=s.length()-1;i>=0;i--){
                if(st.empty()){
                    break;
                }
                if(s[i]==st.top()){
                    ss.insert(i);
                    st.pop();
                }
            }
        }
        for(int i=0;i<s.length();i++){
            
            if(ss.find(i)==ss.end()){
                str += s[i];
            }
            
        }
        
       
        
        return str;
        
    }
};