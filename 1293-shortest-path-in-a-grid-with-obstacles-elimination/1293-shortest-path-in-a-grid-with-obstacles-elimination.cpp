struct triplet
{
   int x, y, k;
};
class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        // BFS
        
        int m = grid.size() , n = grid[0].size();
		
        if(k > n + m - 2) return n + m - 2; // because n + m - 2 is the shortest path in grid
        
        queue<triplet> q;
        unordered_set<string> seen;
        
        q.push({0,0 ,k});
        int steps = 0;
        vector<int> DIRS = {0 , 1 , 0 , -1 , 0};
		
        while(q.empty() == false)
        {
            int size = q.size();
            while(size)
            {
                int r = q.front().x;
                int c = q.front().y; 
                int k = q.front().k;
                
                q.pop();
                   
                if(r == m - 1 and c == n - 1)
                    return steps;
                
                // Pushing valid childs
                for(int i = 0 ; i < 4 ; ++i)
                {
                    int nr = r + DIRS[i];
                    int nc = c + DIRS[i + 1];
                    
                    if(nr < 0 or nc < 0 or nr == m or nc == n)
                        continue;
                    
                    int new_k = k - grid[nr][nc];
                    string state = to_string(nr) + "," + to_string(nc) + "," + to_string(new_k);
                    
                    if(new_k >= 0 and seen.find(state) == seen.end()) // if(we have found a state which we have not seen before!)
                    {
                        q.push({nr , nc , new_k});
                        seen.insert(state);
                    }
                }
                --size;
            }
            ++steps;
        }
        return -1;
    }
};