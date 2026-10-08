class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool>visited(n, false);
        pq.push({0,0});
        int totalcost=0;
        int count=0;
        while(count<n){
            auto[cost, point]=pq.top();
            pq.pop();
            if(visited[point])
            continue;
            visited[point]=true;
            totalcost+=cost;
            count++;

            for(int next=0;next<n;next++){
                if(!visited[next]){
                    int x1= points[point][0];
                    int y1=points[point][1];
                    int x2=points[next][0];
                    int y2=points[next][1];
                    

                    int dist=abs(x1-x2)+abs(y1-y2);
                    pq.push({dist,next});
                }
            }
        }
        return totalcost;
    }
};