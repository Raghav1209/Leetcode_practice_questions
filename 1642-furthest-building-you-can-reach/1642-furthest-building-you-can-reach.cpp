class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> maxB;
        int i,diff;
       for(i=1;i<n;i++){
           
           diff = heights[i]-heights[i-1];
           
           if(diff<=0){
               continue;
           }
           
           bricks -= diff;
           maxB.push(diff);
           
           if(bricks<0){
               bricks += maxB.top();
               maxB.pop();
               ladders--;
           }
           
           if(ladders<0){
               break;
           }
           
       }
        
        return i-1;
        
    }
};