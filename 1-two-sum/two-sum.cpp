class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
//  vector<pair<int,int>> arr;
  unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};