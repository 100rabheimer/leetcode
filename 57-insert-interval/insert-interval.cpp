class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(int i=0; i<intervals.size(); i++){
            vector<int>current=intervals[i];
            if(current[1]<newInterval[0]){
                ans.push_back(current);
            }else if(current[0]<=newInterval[1]){
                newInterval[0]=min(newInterval[0], current[0]);
                newInterval[1]=max(newInterval[1],current[1]);
            }else{
                ans.push_back(newInterval);
                for(int j=i;j<intervals.size();j++){
                    ans.push_back(intervals[j]);
                }
                return ans;
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};