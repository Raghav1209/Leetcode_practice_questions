class Solution {
public:
    int numberOfSteps(int num) {
        
        int n = num;
        int count=0;
        while(num){
            if(num%2==0){
                num = num/2;
            }else{
                num = num-1;
            }
            count++;
        }
        return count;
        
    }
};