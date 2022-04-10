class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum = 0;
        int res = 0;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                
                int x = st.top();
                st.pop();
                sum += x;
                int y = st.top();
                sum += y;
                st.pop();
                st.push(y);
                st.push(x);
                st.push(sum);
                sum = 0;
                
            }else if(ops[i]=="D"){
                int z = 2*st.top();
                // cout<<z<<" ";
                st.push(z);
            }else if(ops[i]=="C"){
                st.pop();
            }else{
                st.push(stoi(ops[i]));
            }
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
            // cout<<st.top()<<" ";
            // st.pop();
        }
        
        return res;
        
    }
};