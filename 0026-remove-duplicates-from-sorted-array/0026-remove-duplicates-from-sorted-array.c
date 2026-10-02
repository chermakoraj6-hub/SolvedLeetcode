int removeDuplicates(int* nums, int numsSize) {
    int k=1;
    int i=0;
    int j=1;
    while(j<numsSize)
    {
        if(nums[j]==nums[j-1])
        {
            j++;
            continue;
        }
        else{nums[i+1]=nums[j];
        i++;
        k++;
        j++;
        }
    }
 return k;
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna