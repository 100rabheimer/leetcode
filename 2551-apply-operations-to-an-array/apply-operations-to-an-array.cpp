class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
          int n = nums.size();

        // Step 1
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2
        int write = 0;

        for (int read = 0; read < n; read++) {
            if (nums[read] != 0) {
                nums[write] = nums[read];
                write++;
            }
        }

        while (write < n) {
            nums[write] = 0;
            write++;
        }

        return nums;
    }
};