
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int sum = 0;

        // Sort the array to enable the two-pointer approach
        Arrays.sort(nums);

        // Store all unique triplets whose sum is zero
        List<List<Integer>> answer = new ArrayList<>();

        // Fix the first number of each triplet
        for (int i = 0; i < nums.length - 2; i++) {

            // Skip duplicate first numbers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Initialize the two pointers
            int j = i + 1;
            int k = nums.length - 1;

            // Search for the remaining two numbers
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // Found a valid triplet
                    answer.add(Arrays.asList(
                        nums[i], nums[j], nums[k]
                    ));

                    // Move both pointers inward
                    j++;
                    k--;

                    // Skip duplicate values at j
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicate values at k
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }

                } else if (sum < 0) {
                    // Increase the sum by moving j forward
                    j++;
                } else {
                    // Decrease the sum by moving k backward
                    k--;
                }
            }
        }

        // Return all unique triplets
        return answer;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna