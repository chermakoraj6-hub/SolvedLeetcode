/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0, right = numsSize - 1, i = numsSize - 1;
    int* output = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    while(left <= right){
        int value;
        if(nums[left] * nums[left] >= nums[right] * nums[right]){
            value = nums[left] * nums[left++];
        }else{
            value = nums[right] * nums[right--];
        }
        output[i--] = value;
    }
    return output;
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna