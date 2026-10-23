class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>change(1001,0);
        for(int i=0;i<trips.size();i++){
    change[trips[i][1]] +=trips[i][0];
      change[trips[i][2]]-=trips[i][0];
        }

        int current=0;
        for(int i=0;i<=1000;i++){
            current+=change[i];
        
        if(current>capacity){
            return false;
        }}

        return true;
    }
};