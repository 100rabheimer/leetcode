class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {



        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Fix one element at a time
        for (int i = 0; i < n - 2; i++) {

            // Agar current element previous ke equal hai,
            // to isse same triplets dubara milenge.
            // Isliye duplicate fixed element skip kar do.
            //
            // Example:
            // [-4, -1, -1, 0, 1, 2]
            //       ↑
            //      i=1  -> process ho chuka
            //          ↑
            //         i=2  -> same -1 hai, skip
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    // Valid triplet mil gaya
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Dono pointers move karo
                    left++;
                    right--;

                    // Left side ke duplicate skip karo
                    //
                    // Example:
                    // [-2,0,0,0,2]
                    //       ↑ ↑
                    // Same 0 dobara use nahi karna
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Right side ke duplicate skip karo
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }

                // Sum chhota hai
                // Bada number chahiye
                else if (sum < 0) {
                    left++;
                }

                // Sum bada hai
                // Chhota number chahiye
                else {
                    right--;
                }
            }
        }

        return ans;

    }
};