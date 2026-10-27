class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;

        // Frequency count
        for(char task : tasks){
            mp[task]++;
        }

        // Maximum frequency
        int maxFreq = 0;

        for(auto x : mp){
            maxFreq = max(maxFreq, x.second);
        }

        // Number of tasks having maximum frequency
        int maxCount = 0;

        for(auto x : mp){
            if(x.second == maxFreq){
                maxCount++;
            }
        }

        // Skeleton length
        int skeleton = (maxFreq - 1) * (n + 1) + maxCount;

        // Actual answer
        return max((int)tasks.size(), skeleton);
    }
};