#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int res = 0;
    int lastIndex[128];
    for(int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }
    
    int start = 0;
    for (int end = 0; end < n; end++) {
        start = max(start, lastIndex[s[end]] + 1);
        res = max(res, end - start + 1);
        lastIndex[s[end]] = end;
    }
    return res;
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna