class Solution {
public:
    
    bool isOperator(char ch){
        // cout<<ch<<" ";
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            return true;
        }else{
            return false;
        } 
    }
    
    int prec(char ch){
        if(ch=='/' || ch== '*'){
            return 2;
        }else if(ch=='+' || ch=='-'){
            return 1;
        }else{
            return 0;
        }
    }
    
    int cal(int val1,int val2,char ch){
        switch(ch){
            case '+':
                return val1+val2;
                
            case '-':
                return val2-val1;
            
            case '*':
                return val1*val2;
                
            case '/':
                return val2/val1;
        }
        return -1;
    }
    
    int convert(string s){
    
        stack<int> nums;
        stack<char> op;

        for(int i=0;i<s.size();i++){
            
            if(s[i]==' '){
                continue;
            }
            
            if(isOperator(s[i])){
                
                while(!op.empty() && prec(op.top())>=prec(s[i])){
                    int val1 = nums.top();
                    nums.pop();
                    int val2 = nums.top();
                    nums.pop();
                    
                    int out = cal(val1,val2,op.top());
                    op.pop();
                    nums.push(out);
                    
                }
                op.push(s[i]);
                
            }else{
                
                long num =0;
                
                while(i<s.size() && isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }
                nums.push(num);
                i--;
                
            }
        }
        
        while(!op.empty()){
            int val1 = nums.top();
            nums.pop();
            int val2 = nums.top();
            nums.pop();

            int out = cal(val1,val2,op.top());
            op.pop();
            nums.push(out);
            
        }
        
        return nums.top();
        
    }
    
    int calculate(string s) {
       
        return convert(s);
    }
};