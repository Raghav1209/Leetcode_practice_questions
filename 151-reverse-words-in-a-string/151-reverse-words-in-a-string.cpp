class Solution {
public:
    
    
    
    string reverseWords(string s) {
        
        stringstream ss(s);
        stack<string> st;
        string str;
        while(ss >> str){
            st.push(str);
        }
        
        s.clear();
        
        while(!st.empty()){
            s += st.top() + " ";
            st.pop();
        }
        s.pop_back();
        return s;
        
    }
};