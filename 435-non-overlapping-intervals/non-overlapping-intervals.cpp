class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        vector<int>prev=intervals[0];
        int count=0;
        for(int i=1;i<intervals.size();i++){
            vector<int>current=intervals[i];
            if(current[0]<prev[1]){//overlap krega
count++;
if(prev[1]>current[1]){//jiska end bda hain use remove
prev=current;
}
            }
else{
    prev=current;//current interval is safe ise keep kro and ab next interval ko current se compare krenge 
}
            }
            return count;


        }
    
};