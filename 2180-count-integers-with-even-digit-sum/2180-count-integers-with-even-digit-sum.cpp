class Solution {
public:
    int countEven(int num) {
        int count=0;
        for(int i=1;i<=num;i++){
            // int x;
            // if(i%9!=0){
                // x = i%9;
                // if(x==1){
                    int sum = 0;
                    int j = i;
                    while(j){
                        sum += (j%10);
                        j=j/10;
                    }
                    if(sum%2==0){
                        count++;
                        cout<<i<<" ";
                    }
                    // continue;
                // }
                // if(x%2==0){
                //     count++;
                //     cout<<i<<" ";
                // }
            }
        return count;
    }
};