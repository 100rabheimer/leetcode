class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1]>b[1];
        });
int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            int take= min(boxTypes[i][0], truckSize);
            ans+=take*boxTypes[i][1];
            truckSize-=take;

            if(truckSize==0)
            break;
        }
        return ans;
    }
};