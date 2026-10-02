class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0;
        int res=1;
        int j=1;
        int l=nums.length;
        while(j<l)
        {
            if(nums[j]==nums[j-1])
            {
                j++;
                continue;
            }
            else{
                nums[i+1]=nums[j];
                i++;
                res++;
                j++;
            }
        }
        return res;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna