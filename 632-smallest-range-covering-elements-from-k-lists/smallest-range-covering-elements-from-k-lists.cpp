class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
     priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int currentMax = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i].empty()) {
                pq.push({nums[i][0], i, 0});
                currentMax = max(currentMax, nums[i][0]);
            }
        }

        int bestRange = INT_MAX;
        int bestL = 0;
        int bestR = 0;

        while (!pq.empty()) {

            auto [value, i, j] = pq.top();
            pq.pop();

            int range = currentMax - value;

            if (range < bestRange) {
                bestRange = range;
                bestL = value;
                bestR = currentMax;
            }

            if (j + 1 < nums[i].size()) {
                pq.push({nums[i][j + 1], i, j + 1});
                currentMax = max(currentMax, nums[i][j + 1]);
            }
            else {
                break;
            }
        }

        return {bestL, bestR};
        
    }
};