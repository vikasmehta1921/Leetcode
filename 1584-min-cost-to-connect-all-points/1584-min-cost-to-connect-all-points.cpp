class Solution {
public:
    int manhattendist(vector<vector<int>>& points , int p , int q){
        return abs(points[p][0]-points[q][0]) +
                abs(points[p][1]-points[q][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // priority queue;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        // bool vector set 
        vector<bool> mstset(n,false);
        int mstcost = 0;

        pq.push({0,0});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;

            if(mstset[node]) continue;
            mstset[node] = true;
            mstcost += wt;

            for(int i = 0 ; i < n ; i++){
                if(!mstset[i]){
                    int edgewt = manhattendist(points,node , i);
                    pq.push({edgewt , i});
                }
            }
        }

        return mstcost;
        
    }
};